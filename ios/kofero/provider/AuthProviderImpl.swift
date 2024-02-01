//
//  AuthProviderImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 23/1/24.
//

import Foundation
import presenter
import UIKit
import SwiftyJSON

class AuthProviderImpl: AuthProvider {
    private let restManager: RestManager
    private let fileManager: IFileManager
    private let loggingProvider: LoggingProvider
    private let arrowExtensions = ArrowExtensions()
    private let path:String = "auth"
    private let urlPrefix: String
    private let syncObject = NSObject()
    
    
    init(restManager: RestManager, fileManager:IFileManager, loggingProvider:LoggingProvider, urlPrefix:String){
        self.restManager = restManager
        self.fileManager = fileManager
        self.loggingProvider = loggingProvider
        self.urlPrefix = urlPrefix
    }
    
    
    //TODO: FIX, only works with 200s
    private func getRestClosure(dataClosure: @escaping (Data) -> Void) -> RestClosure {
        return {[self] data,response,error in
            if let uResponse = response as? HTTPURLResponse {
                if let uData = data {
                    if(uResponse.statusCode == 200) {
                        saveToDisk(data: uData)
                        dataClosure(uData)
                    }
                }
            }
        }
    }
    
    
    func get() -> Arrow_coreEither<ModelProviderError, NSString> {
        print("@#@# GET AUTH")
        return synchronized(syncObject){ () -> Arrow_coreEither<ModelProviderError, NSString> in
            do{
                return arrowExtensions.buildImageEitherRight(right: String(data: try Data(contentsOf: makeUrl()), encoding: .utf8)!)
            }
            catch{
                let group = DispatchGroup()
                var data: Data? = nil
                group.enter()
                var request = URLRequest(url: URL(string: urlPrefix + "/auth/register")!)
                request.httpMethod = "PUT"
                request.allHTTPHeaderFields?["Content-Type"] = "application/json"
                request.httpBody = ("{\"prefixedUid\":\"koferoAuth||" + UIDevice.current.identifierForVendor!.uuidString + "\"}").data(using: .utf8)
                restManager.dataTask(with: request, completionHandler: getRestClosure{ [self] ndata in
                    self.loggingProvider.log(level: .debug, logTag: "AuthProvider", message: "\(String(describing: String(data: ndata, encoding: .utf8)))")
                    data = ndata
                    group.leave()
                }).resume()
                group.wait()
                if let uData = data {
                    do{
                        let json = try JSON(data: uData)
                        return arrowExtensions.buildImageEitherRight(right: json["token"].stringValue)
                    }catch{
                        return arrowExtensions.buildImageEitherLeft(left: ModelIncorrectCount(ids: []))
                    }
                } else{
                    return arrowExtensions.buildImageEitherLeft(left: ModelIncorrectCount(ids: []))
                }
            }
        }
    }
    
    private func saveToDisk(data: Data){
        let path = makeUrl()
        do {
            let json = try JSON(data: data)
            try json["token"].stringValue.data(using: .utf8)?.write(to: path)
        } catch {
            loggingProvider.log(level: .debug, logTag: "AuthProvider", message: error.localizedDescription)
            print(error.localizedDescription)
        }
    }
    
    private func getDocumentsDirectory() -> URL {
        let paths = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        return paths[0]
    }
    
    
    private func makeUrl() -> URL {
        var ret: URL!
        do {
            ret = try FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: false).appendingPathComponent("koferoAuth.txt")
        }
        catch {
            loggingProvider.log(level: .debug, logTag: "ImageProvider", message: "makeUrl error: \(error)")
        }
        return ret
    }
    
    
}

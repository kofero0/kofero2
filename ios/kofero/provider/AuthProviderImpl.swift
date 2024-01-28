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
    
    
    init(restManager: RestManager, fileManager:IFileManager, loggingProvider:LoggingProvider, urlPrefix:String){
        self.restManager = restManager
        self.fileManager = fileManager
        self.loggingProvider = loggingProvider
        self.urlPrefix = urlPrefix
    }
    
    
    
    private func getRestClosure(dataClosure: @escaping (Data) -> Void) -> RestClosure {
        return {[self] data,response,error in
            print("HI")
            if let uResponse = response as? HTTPURLResponse {
                print("HII")
                if let uData = data {
                    print("YO")
                    print(uResponse.statusCode)
                    if(uResponse.statusCode == 200) {
                        print("NOPE")
                        saveToDisk(data: uData)
                        dataClosure(uData)
                    }
                }
            }
        }
    }
    
    
    func get() -> Arrow_coreEither<ModelProviderError, NSString> {
        print("GETTING AUTH")
        do{
            print("FINDING AUTH ON DISK")
            //return arrowExtensions.buildImageEitherRight(right: "0||0858cfa32b700b179f75168c19af0160f57aa7de501275fd845d19bae23e7dbe")
            return arrowExtensions.buildImageEitherRight(right: String(data: try Data(contentsOf: makeUrl()), encoding: .utf8)!)
        }
        catch{
            print("COULDNT FIND IT")
            let group = DispatchGroup()
            var data: Data? = nil
            group.enter()
            
            print("IN GROUP")
            var request = URLRequest(url: URL(string: urlPrefix + "/auth/register")!)
            request.httpMethod = "PUT"
            request.allHTTPHeaderFields?["Content-Type"] = "application/json"
            request.httpBody = ("{\"prefixedUid\":\"koferoAuth||" + UIDevice.current.identifierForVendor!.uuidString + "\"}").data(using: .utf8)
            print(String(data: request.httpBody!, encoding: .utf8))
            restManager.dataTask(with: request, completionHandler: getRestClosure{ [self] ndata in
                print("HELLO")
                self.loggingProvider.log(level: .debug, logTag: "AuthProvider", message: "\(String(describing: String(data: ndata, encoding: .utf8)))")
                data = ndata
                group.leave()
            }).resume()
            group.wait()
            if let uData = data {
                return arrowExtensions.buildImageEitherRight(right: String(data: uData, encoding: .utf8)!)
            } else{
                return arrowExtensions.buildImageEitherLeft(left: ModelIncorrectCount(ids: []))
            }
        }
    }
    
    private func saveToDisk(data: Data){
        let path = makeUrl()
        do {
            try data.write(to: path, options: .atomic)
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

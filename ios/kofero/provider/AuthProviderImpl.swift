//
//  AuthProviderImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 23/1/24.
//

import Foundation
import presenter
import UIKit

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
        do{
            return arrowExtensions.buildImageEitherRight(right: String(data: try Data(contentsOf: makeUrl()), encoding: .utf8)!)
        }
        catch{
                let group = DispatchGroup()
                var data: Data? = nil
                group.enter()
            var request = URLRequest(url: URL(string: urlPrefix + "/\(path)/register")!)
            request.httpMethod = "PUT"
            request.httpBody = ("{\"prefixedAuth\": \"koferoAuth||" + UIDevice.current.identifierForVendor!.uuidString + "}").data(using: .utf8)
            restManager.dataTask(with: request, completionHandler: getRestClosure{ [self] ndata in
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

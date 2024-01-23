//
//  AuthProviderImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 23/1/24.
//

import Foundation
import presenter

class AuthProviderImpl: AuthProvider {
    private let restManager: RestManager
    private let fileManager: IFileManager
    private let loggingProvider: LoggingProvider
    private let arrowExtensions = ArrowExtensions()
    private let path:String = "auth"
    
    init(restManager: RestManager, fileManager:IFileManager, loggingProvider:LoggingProvider){
        self.restManager = restManager
        self.fileManager = fileManager
        self.loggingProvider = loggingProvider
    }
    
    
    
    private func getRestClosure(url:String, dataClosure: @escaping (Data) -> Void) -> RestClosure {
        return {[self] data,response,error in
            if let uResponse = response as? HTTPURLResponse {
                if let uData = data {
                    if(uResponse.statusCode == 200) {
                        saveToDisk(data: uData, url: url)
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
                //loggingProvider.log(level: .debug, logTag: "ImageProvider", message: "\(url) not on disk")
                restManager.dataTask(with: URLRequest(url: uRL), completionHandler: getRestClosure(url:url){ndata in
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
        return arrowExtensions.buildImageEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
    private func saveToDisk(data: Data, url: String){
        let path = makeUrl(string: url)
        do {
            try data.write(to: path, options: .atomic)
        } catch {
            loggingProvider.log(level: .debug, logTag: "ImageProvider", message: error.localizedDescription)
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

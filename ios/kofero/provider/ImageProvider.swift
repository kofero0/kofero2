//
//  ImageProvider.swift
//  provider
//
//  Created by Mitchell Drew on 26/2/21.
//

import Foundation
import presenter


open class ImageProviderImpl: ImageProvider {
    public let restManager:RestManager
    private let loggingProvider:LoggingProvider
    private let arrowExtensions = ArrowExtensions()
    
    public init(loggingProvider: LoggingProvider){
        self.restManager = URLSession.shared
        self.loggingProvider = loggingProvider
    }
    
    private func makeUrl(string:String) -> URL {
        var ret: URL!
        do {
            ret = try FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: false).appendingPathComponent("\(string[string.index(string.startIndex, offsetBy: 19)...])")
        }
        catch {
            loggingProvider.log(level: .debug, logTag: "ImageProvider", message: "makeUrl error: \(error)")
        }
        return ret
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
    
    public func get(url: String) async throws -> Arrow_coreEither<ModelProviderError, NSString> {
        do{
            return arrowExtensions.buildImageEitherRight(right: String(data: try Data(contentsOf: makeUrl(string: url)), encoding: .utf8)!)
        }
        catch{
            if let uRL = URL(string: url) {
                let group = DispatchGroup()
                var data: Data? = nil
                group.enter()
                loggingProvider.log(level: .debug, logTag: "ImageProvider", message: "\(url) not on disk")
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
        }
        return arrowExtensions.buildImageEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
}

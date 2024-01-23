//
//  StatusProvider.swift
//  kofero
//
//  Created by Mitchell Drew on 17/1/24.
//

import Foundation
import presenter


//TODO: DEPRECATED, REPLACE
class StatusProviderImpl: StatusProvider {
    public let restManager:RestManager
    private let loggingProvider:LoggingProvider
    private let url:URL
    private let mapper:StatusMapper
    private let arrowExtensions = ArrowExtensions()
    
    public init(loggingProvider: LoggingProvider, url:URL, statusMapper:StatusMapper){
        self.mapper = statusMapper
        self.restManager = URLSession.shared
        self.loggingProvider = loggingProvider
        self.url = url
    }
    
    
    private func isResponseGood(data:Data?, response:URLResponse?, error:Error?) -> Bool {
        return data != nil && (response as! HTTPURLResponse).statusCode == 200 && error == nil
    }
    
    func getBackendStatus() async throws -> Arrow_coreEither<ModelProviderError, ModelStatus> {
        
            let group = DispatchGroup()
        var providerError: ModelProviderError? = nil
        var status: ModelStatus? = nil
        group.enter()
        
        
        let task = restManager.dataTask(with: URLRequest(url: url)){[self] data, response, error in
            if(isResponseGood(data:data, response:response, error:error)){
                do{
                    status = try mapper.map(data: data!)
                }
                catch {
                    providerError = ModelHttpError(statusCode: 999, response: String(describing: response))
                }
            }
            else{
                if let uResponse = response as? HTTPURLResponse{
                    if let responseData = String(data: data!, encoding: .utf8) {
                        providerError = ModelHttpError(statusCode: Int32(uResponse.statusCode), response: responseData)
                    }
                }
            }
            group.leave()
        }
        task.resume()
        group.wait()
        
        if let uPError = providerError {
            return arrowExtensions.buildStatusEitherLeft(left: uPError)
        }
        if let uStatus = status {
            return arrowExtensions.buildStatusEitherRight(right: uStatus)
        }
        return arrowExtensions.buildStatusEitherLeft(left: ModelOtherError())
    }
    
    func getLocalStatus() async throws -> ModelStatus {
        return ModelStatus(time: Int64(Date().timeIntervalSince1970), version: Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as! String)
    }
}

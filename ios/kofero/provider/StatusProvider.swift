//
//  StatusProvider.swift
//  kofero
//
//  Created by Mitchell Drew on 17/1/24.
//

import Foundation
import presenter

class StatusProviderImpl: StatusProvider {
    public let restManager:RestManager
    private let loggingProvider:LoggingProvider
    private let arrowExtensions = ArrowExtensions()
    
    public init(core:ProviderCore, loggingProvider: LoggingProvider){
        self.restManager = core.restManager
        self.loggingProvider = loggingProvider
    }
    
    
    
    func getBackendStatus() async throws -> Arrow_coreEither<ModelProviderError, ModelStatus> {
        
    }
    
    func getLocalStatus() async throws -> ModelStatus {
        return ModelStatus(time: Int64(Date().timeIntervalSince1970), version: Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as! String)
    }
}

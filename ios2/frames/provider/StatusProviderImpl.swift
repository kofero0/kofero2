//
//  StatusProvider.swift
//  kofero
//
//  Created by Mitchell Drew on 17/1/24.
//

import Foundation
import presenter


//TODO: figure out why Info.plist doesnt work for version
class StatusProviderImpl: AbstractStatusProvider {
    init(client: Ktor_client_coreHttpClient, urlPrefix: String, mapper: StatusMapper) {
        super.init(client: client, urlPrefix: urlPrefix, mapper: mapper)
    }
    
    override func getLocalStatus() -> ModelStatus {
        //return ModelStatus(time: Int64(Date().timeIntervalSince1970), version: Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as! String)
        return ModelStatus(time: Int64(Date().timeIntervalSince1970), version: "0.0.018")
    }
}

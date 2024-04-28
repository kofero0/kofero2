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
    init(client: Ktor_client_coreHttpClient, urlPrefix: String, mapper: StatusMapper, diskAccessor: DiskAccessor) {
        super.init(client: client, urlPrefix: urlPrefix, mapper: mapper, diskAccessor: diskAccessor)
    }
}

//
//  MoveComponent.swift
//  debug
//
//  Created by Mitchell Drew on 12/3/21.
//

import Foundation
import presenter
import SwiftyJSON
import NeedleFoundation

protocol MoveDependency: Dependency {
    var jsonEncoder:StringEncoder<[JSON]> {get}
    var loggingProvider:LoggingProvider {get}
    var authProvider: AuthProvider {get}
    var urlPrefix: String {get}
    var requestMapper: RequestMapper {get}
    var diskAccessor: DiskAccessor {get}
    var authHttpClient: Ktor_client_coreHttpClient {get}
}

class MoveComponent: Component<MoveDependency> {
    var provider: ProviderAbstract<ModelMove> {
        return MoveProviderImpl(client: dependency.authHttpClient, jsonFilename: "move", urlPrefix: dependency.urlPrefix, mapper: mapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var mapper:MoveMapper{
        return MoveMapperImpl(encoder: dependency.jsonEncoder)
    }
}

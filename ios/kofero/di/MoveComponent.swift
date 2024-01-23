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
    var providerCore:ProviderCore {get}
    var jsonEncoder:StringEncoder<[JSON]> {get}
    var loggingProvider:LoggingProvider {get}
    var authProvider: AuthProvider {get}
    var urlPrefix: String {get}
    var requestMapper: RequestMapper {get}
    var diskAccessor: DiskAccessor {get}
}

class MoveComponent: Component<MoveDependency> {
    var provider: MoveProviderImpl {
        return MoveProviderImpl(client: HttpClientProvider().provideAuth(authProvider: dependency.authProvider), jsonFilename: "move", urlPrefix: dependency.urlPrefix, mapper: mapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var mapper:MoveMapper{
        return MoveMapperImpl(encoder: dependency.jsonEncoder)
    }
}

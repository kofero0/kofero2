//
//  CharacterComponent.swift
//  debug
//
//  Created by Mitchell Drew on 11/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftUI
import SwiftyJSON

protocol CharacterDependency: Dependency {
    var moveProvider: ProviderAbstract<ModelMove> {get}
    var imageProvider: ImageProvider {get}
    var jsonEncoder:StringEncoder<[JSON]> {get}
    var bannerAdUnitId: String {get}
    var loggingProvider: LoggingProvider {get}
    var stateLogger: StateLogger {get}
    var stateReducer: StateReducer {get}
    var dispatcherProvider: DispatcherProvider {get}
    var authProvider: AuthProvider {get}
    var urlPrefix: String {get}
    var requestMapper: RequestMapper {get}
    var diskAccessor: DiskAccessor {get}
    var authHttpClient: Ktor_client_coreHttpClient {get}
}

class CharacterComponent: Component<CharacterDependency> {
    var provider: ProviderAbstract<ModelCharacter> {
        return CharProviderImpl(client: dependency.authHttpClient, jsonFilename: "char", urlPrefix: dependency.urlPrefix, mapper: mapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var mapper: CharMapper {
        return CharacterMapperImpl(encoder: dependency.jsonEncoder)
    }
    
    var presenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: provider, moveProvider: dependency.moveProvider, imageProvider: dependency.imageProvider)
    }
}

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
    var charProvider: ProviderAbstract<ModelCharacter> {
        return CharProviderImpl(client: dependency.authHttpClient, jsonFilename: "char", urlPrefix: dependency.urlPrefix, mapper: charMapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var charMapper: CharacterMapperImpl {
        return CharacterMapperImpl(encoder: dependency.jsonEncoder)
    }
    
    var charPresenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: charProvider, moveProvider: dependency.moveProvider, imageProvider: dependency.imageProvider)
    }
}

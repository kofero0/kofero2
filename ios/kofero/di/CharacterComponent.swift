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
}

class CharacterComponent: Component<CharacterDependency>, CharViewBuilder {
    var provider: ProviderAbstract<ModelCharacter> {
        return CharProviderImpl(client: HttpClientProvider().provideAuth(authProvider: dependency.authProvider), jsonFilename: "char", urlPrefix: dependency.urlPrefix, mapper: mapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var mapper: CharMapper {
        return CharacterMapperImpl(encoder: dependency.jsonEncoder)
    }
    
    var presenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: provider, moveProvider: dependency.moveProvider, imageProvider: dependency.imageProvider)
    }
    
    var interactor: CharacterInteractor {
        return CharacterInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, router: router, context: dependency.dispatcherProvider.default_)
    }
    
    var router: CharacterRouter {
        return CharRouterImpl()
    }
    
    func characterView(id:Int32) -> AnyView {
        return AnyView(CharView(charId: id, interactor: interactor, adUnitId: dependency.bannerAdUnitId))
    }
}

protocol CharViewBuilder {
    func characterView(id:Int32) -> AnyView
}

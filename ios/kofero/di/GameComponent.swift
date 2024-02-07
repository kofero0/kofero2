//
//  GameComponent.swift
//  debug
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftyJSON
import SwiftUI

protocol GameDependency: Dependency {
    var imageProvider:ImageProvider {get}
    var charProvider:ProviderAbstract<ModelCharacter> {get}
    var jsonEncoder:StringEncoder<[JSON]> {get}
    var bannerAdUnitId:String {get}
    var loggingProvider:LoggingProvider {get}
    var stateLogger: StateLogger {get}
    var stateReducer: StateReducer {get}
    var dispatcherProvider: DispatcherProvider {get}
    var authProvider: AuthProvider {get}
    var urlPrefix: String {get}
    var requestMapper: RequestMapper {get}
    var diskAccessor: DiskAccessor {get}
    var charInteractor: CharacterInteractor {get}
    var authHttpClient: Ktor_client_coreHttpClient {get}
}

class GameComponent: Component<GameDependency> {
    var gameProvider: ProviderAbstract<ModelGame> {
        return GameProviderImpl(client: dependency.authHttpClient, jsonFilename: "game", urlPrefix: dependency.urlPrefix, mapper: gameMapper, requestMapper: dependency.requestMapper, diskAccessor: dependency.diskAccessor)
    }
    
    var gameMapper: GameMapper {
        return GameMapperImpl(encoder: dependency.jsonEncoder)
    }
    
    var presenter: GamePresenter {
        return GamePresenterImpl(characterProvider: dependency.charProvider, gameProvider: gameProvider, imageProvider: dependency.imageProvider, loggingProvider: dependency.loggingProvider)
    }
    
    var interactor: GameInteractor {
        return GameInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, context: dependency.dispatcherProvider.default_)
    }
    
    var gameView: GameView {
        return GameView(charInteractor: dependency.charInteractor, gameInteractor: interactor, adUnitId: dependency.bannerAdUnitId)
    }
    
}

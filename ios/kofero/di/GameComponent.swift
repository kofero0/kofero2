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
    var providerCore:ProviderCore {get}
    var characterProvider:Provider {get}
    var jsonEncoder:DataEncoder<[JSON]> {get}
    var charViewBuilder:CharacterViewBuilder {get}
    var bannerAdUnitId:String {get}
    var loggingProvider:LoggingProvider {get}
    var uiApplication:UIApplication {get}
    var stateLogger: StateLogger {get}
    var stateReducer: StateReducer {get}
    var dispatcherProvider: DispatcherProvider {get}
}

class GameComponent: Component<GameDependency>{
    
    var gameProvider: GameProvider {
        return ProviderImpl(core: dependency.providerCore, url: url, mapper: mapper, jsonFilename: jsonFilename, loggingProvider: dependency.loggingProvider) as! GameProvider
    }
    
    var mapper: DataMapper<[ModelGame]> {
        return GameMapper(encoder: dependency.jsonEncoder)
    }
    
    var jsonFilename:String {
        return "game"
    }
    
    var url:URL {
        return URL(string: "https://google.com")!
    }
    
    var presenter: GamePresenter {
        return GamePresenterImpl(characterProvider: dependency.characterProvider, gameProvider: gameProvider, imageProvider: dependency.imageProvider)
    }
    
    var interactor: GameInteractor {
        return GameInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, router: router, context: dependency.dispatcherProvider.default_)
    }
    
    var router: Router {
        return GameRouter(dependency.charViewBuilder, dependency.uiApplication, dependency.characterProvider)
    }
    
    func gameView(id:Int32) -> ContentView {
        
        return ContentView()
        //return GameView(interactor: interactor, gameId: id, adUnitId: dependency.bannerAdUnitId)
    }
    
}

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

protocol GameDependency: Dependency {
    var imageProvider:ImageProvider {get}
    var providerCore:ProviderCore {get}
    var characterProvider:Provider {get}
    var jsonEncoder:DataEncoder<[JSON]> {get}
    var charViewBuilder:CharacterViewBuilder {get}
    var bannerAdUnitId:String {get}
    var loggingProvider:LoggingProvider {get}
    var uiApplication:UIApplication {get}
}

class GameComponent: Component<GameDependency>, GameViewBuilder{
    
    var gameProvider: Provider {
        return ProviderImpl(core: dependency.providerCore, url: url, mapper: mapper, jsonFilename: jsonFilename, loggingProvider: dependency.loggingProvider)
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
        return GameInteractorImpl(presenter: presenter, stateLogger: <#T##StateLogger#>, stateReducer: <#T##StateReducer#>, loggingProvider: dependency.loggingProvider, router: <#T##Router#>, context: <#T##KotlinCoroutineContext#>)
    }
    
    var router: Router {
        return GameRouter(dependency.charViewBuilder, dependency.uiApplication, dependency.characterProvider)
    }
    
    func gameView(id:Int32) -> UIViewController {
        return GameView(interactor: interactor, gameId: id, adUnitId: dependency.bannerAdUnitId)
    }
    
}

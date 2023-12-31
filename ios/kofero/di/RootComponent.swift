//
//  RootComponent.swift
//  debug
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftyJSON
import SwiftUI

class RootComponent: BootstrapComponent {
    var homeComponent: HomeComponent {
        return HomeComponent(parent: self)
    }
    
    var gameComponent: GameComponent {
        return GameComponent(parent: self)
    }
    
    var characterComponent: CharacterComponent {
        return CharacterComponent(parent: self)
    }
    
    var moveComponent: MoveComponent {
        return MoveComponent(parent: self)
    }
    
    var moveProvider: MoveProvider {
        return moveComponent.provider
    }
    
    var charProvider: CharacterProvider {
        return characterComponent.provider
    }
    
    var gameProvider: GameProvider {
        return gameComponent.gameProvider
    }
    
    var rootPresenter: RootPresenter {
        return RootPresenterImpl(gameProvider: gameProvider, loggingProvider: loggingProvider)
    }
    
    var imageProvider:ImageProvider {
        return ImageProviderImpl(core: providerCore, loggingProvider: loggingProvider)
    }
    
    var providerCore:ProviderCore {
        return ProviderCore(restManager: restManager, fileManager: fileManager, userDefaults: userDefaults, requestEncoder: requestEncoder)
    }
    
    var restManager:RestManager {
        return URLSession.shared
    }
    
    var fileManager:IFileManager {
       return FileManager()
    }
    
    var userDefaults:IUserDefaults {
        return UserDefaults.standard
    }
    
    var jsonEncoder:DataEncoder<[JSON]> {
        return JsonDataEncoder<[JSON]>()
    }
    
    var requestEncoder:DataEncoder<[Int32]> {
        return JsonDataEncoder<[Int32]>()
    }
    
    var gameViewBuilder:GameViewBuilder{
        return gameComponent
    }
    
    var charViewBuilder:CharViewBuilder{
        return characterComponent
    }
    
    var homeViewBuilder: HomeViewBuilder {
        return homeComponent
    }
    
    var bannerAdUnitId: String {
        return "ca-app-pub-8614671926563443/4610731994"
    }
    
    var navController: UINavigationController {
        return UINavigationController(rootViewController: UIHostingController(rootView: RootView()))
    }
    
    var favoritesProvider:FavoritesProvider {
        return FavoritesProviderImpl(defaults: userDefaults)
    }
    
    var loggingProvider: LoggingProvider {
        return LoggingProviderImpl()
    }
    
    var stateLogger: StateLogger {
        return StateLoggerImpl(stateRepository: stateRepository, loggingProvider: loggingProvider)
    }
    
    var stateRepository: StateProvider {
        return StateProviderImpl()
    }
    
    var stateReducer: StateReducer {
        return StateReducerImpl()
    }
    
    var dispatcherProvider: DispatcherProvider {
        return DispatcherProvider()
    }
}

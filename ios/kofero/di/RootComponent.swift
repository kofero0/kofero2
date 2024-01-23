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
    
    var moveProvider: ProviderAbstract<ModelMove> {
        return moveComponent.provider
    }
    
    var charProvider: ProviderAbstract<ModelCharacter> {
        return characterComponent.provider
    }
    
    var gameProvider: ProviderAbstract<ModelGame> {
        return gameComponent.gameProvider
    }
    
    var statusProvider: StatusProvider {
        return StatusProviderImpl(loggingProvider: loggingProvider, url: URL(string: "https://google.com")!, statusMapper: StatusMapper(encoder: jsonEncoder))
    }
    
    var rootPresenter: RootPresenter {
        return RootPresenterImpl(statusProvider: statusProvider, loggingProvider: loggingProvider)
    }
    
    var imageProvider:ImageProvider {
        return ImageProviderImpl(loggingProvider: loggingProvider)
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
    
    var jsonEncoder:StringEncoder<[JSON]> {
        return JsonStringEncoder<[JSON]>()
    }
    
    var requestEncoder:RequestMapper {
        return RequestMapperImpl()
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
    
    var stateReducer: StateReducer {
        return StateReducerImpl()
    }
    
    var dispatcherProvider: DispatcherProvider {
        return DispatcherProvider()
    }
    
    var authProvider: AuthProvider {
        return AuthProviderImpl()
    }
}

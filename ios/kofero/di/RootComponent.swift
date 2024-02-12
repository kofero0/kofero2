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
    var urlPrefix: String {
        return "http://localhost:8080"
    }
    
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
    
    var bannerAdUnitId: String {
        return "ca-app-pub-8614671926563443/4610731994"
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
    
    var identityProvider: IdentityProvider{
        return IdentityProviderImpl()
    }
    
    var authProvider: AuthProvider {
        return AuthProviderImpl(client: noAuthHttpClient, urlPrefix: urlPrefix, diskAccessor: AuthDiskAccessorImpl(), authMapper: AuthMapperImpl(), identityProvider: identityProvider)
    }
    
    var stateMapper: StringMapper<[KotlinLong:ModelEvent]> {
        return StateMapperImpl()
    }
    
    var stateLogger: StateLogger {
        return StateLoggerImpl()
    }
    
    var requestMapper: RequestMapper {
        return RequestMapperImpl()
    }
    
    var diskAccessor: DiskAccessor {
        return DiskAccessorImpl()
    }
    
    var statusMapper: StatusMapper{
        return StatusMapperImpl()
    }
    
    var statusProvider: StatusProvider {
        return StatusProviderImpl(client: authHttpClient, urlPrefix: urlPrefix, mapper: statusMapper)
    }
    
    var rootInteractor: RootInteractor{
        return RootInteractorImpl(presenter: rootPresenter, stateLogger: stateLogger, stateReducer: StateReducerImpl(), loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider)
    }
    
    var rootView: RootView {
        return RootView(interactor: rootInteractor, homeView: homeView, gameView: gameView, charView: charView)
    }
    
    var homeView: HomeView {
        return homeComponent.homeView
    }
    
    var charInteractor: CharacterInteractor {
        return shared { CharacterInteractorImpl(presenter: characterComponent.presenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_) }
    }
    
    var homeInteractor: HomeInteractor {
        return homeComponent.interactor
    }
    
    var gameInteractor: GameInteractor {
        return shared { GameInteractorImpl(presenter: gameComponent.presenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
        }
    }
    
    var gameView: GameView {
        return shared { GameView(charInteractor: charInteractor, gameInteractor: gameInteractor, adUnitId: bannerAdUnitId) }
    }
    
    var charView: CharView {
        return CharView(interactor: charInteractor, adUnitId: bannerAdUnitId)
    }
    
    var noAuthHttpClient: Ktor_client_coreHttpClient{
        return HttpClientProvider().provideNoAuth()
    }
    
    var authHttpClient: Ktor_client_coreHttpClient {
        return HttpClientProvider().provideAuth(authProvider: authProvider)
    }
}

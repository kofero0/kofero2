//
//  RootComponent.swift
//  debug
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import presenter
import SwiftyJSON
import SwiftUI

class RootComponent {
    
    var urlPrefix: String {
        return "https://kofero.org"
    }
    
    var bannerAdUnitId: String {
        return "ca-app-pub-8614671926563443/4610731994"
    }
    
    //MARK: ROOT
    
    var rootView: RootView {
        return RootView(interactor: rootInteractor, homeView: homeComponent.homeView, gameView: gameComponent.gameView, charView: characterComponent.charView, searchView: searchView)
    }
    
    var rootPresenter: RootPresenter {
        return RootPresenterImpl(statusProvider: statusProvider, authProvider: authProvider, gameProvider: gameComponent.gameProvider, charProvider: characterComponent.charProvider, moveProvider: moveProvider, loggingProvider: loggingProvider)
    }
    
    var rootInteractor: RootInteractor{
        return RootInteractorImpl(presenter: rootPresenter, stateLogger: stateLogger, stateReducer: StateReducerImpl(), loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider)
    }
    
    //MARK: HOME
    
    var homeComponent: HomeComponent{
        return HomeComponent(copyProvider: copyProvider, gameProvider: gameComponent.gameProvider, imageProvider: imageProvider, favoritesProvider: favoritesProvider, loggingProvider: loggingProvider, stateLogger: stateLogger, stateReducer: stateReducer, dispatcherProvider: dispatcherProvider, gameInteractor: gameComponent.gameInteractor, charInteractor: characterComponent.charInteractor)
    }
    
    //MARK: GAME
    
    var gameComponent: GameComponent {
        return GameComponent(authHttpClient: authHttpClient, urlPrefix: urlPrefix, requestMapper: requestMapper, diskAccessor: diskAccessor, jsonEncoder: jsonEncoder, charProvider: characterComponent.charProvider, imageProvider: imageProvider, loggingProvider: loggingProvider, stateLogger: stateLogger, stateReducer: stateReducer, dispatcherProvider: dispatcherProvider, charInteractor: characterComponent.charInteractor, favoritesProvider: favoritesProvider)
    }
    
    
    //MARK: CHARACTER
    
    var characterComponent: CharacterComponent {
        return CharacterComponent(authHttpClient: authHttpClient, urlPrefix: urlPrefix, requestMapper: requestMapper, diskAccessor: diskAccessor, jsonEncoder: jsonEncoder, imageProvider: imageProvider, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider, favoritesProvider: favoritesProvider, gameProvider: gameComponent.gameProvider, moveProvider: )
    }
    
    //MARK: SEARCH
    
    var searchInteractor: SearchInteractor {
        return SearchInteractorImpl()
    }
    
    var searchPresenter: SearchPresenter {
        return SearchPresenterImpl()
    }
    
    var searchView: SearchView {
        return SearchView(searchInteractor: searchInteractor, gameInteractor: gameInteractor, charInteractor: charInteractor)
    }
    
    //MARK: MOVE
    
    var moveProvider: ProviderAbstract<ModelMove> {
        return MoveProviderImpl(client: authHttpClient, jsonFilename: "move", urlPrefix: urlPrefix, mapper: moveMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
    }
    
    var moveMapper:MoveMapper{
        return MoveMapperImpl(encoder: jsonEncoder)
    }
    
    //MARK: PROVIDER
    
    var dispatcherProvider: DispatcherProvider {
        return DispatcherProvider()
    }
    
    var statusProvider: StatusProvider {
        return StatusProviderImpl(client: authHttpClient, urlPrefix: urlPrefix, mapper: statusMapper)
    }
    
    var copyProvider: CopyProvider {
        return CopyProviderImpl(client: authHttpClient, jsonFilename: "copy", urlPrefix: urlPrefix, mapper: CopyMapperImpl(), diskAccessor: diskAccessor)
    }
    
    var authProvider: AuthProvider {
        return AuthProviderImpl(client: noAuthHttpClient, urlPrefix: urlPrefix, diskAccessor: AuthDiskAccessorImpl(), authMapper: AuthMapperImpl(), identityProvider: identityProvider)
    }
    
    var identityProvider: IdentityProvider{
        return IdentityProviderImpl()
    }
    
    var favoritesProvider:FavoritesProvider {
        return FavoritesProviderImpl(loggingProvider: loggingProvider, diskAccessor: diskAccessor, mapper: FavoritesMapper(encoder: jsonEncoder, gameMapper: gameMapper, charMapper: charMapper))
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
    
    var loggingProvider: LoggingProvider {
        return ReleaseLoggingProvider()
    }
    
    var stateReducer: StateReducer {
        return StateReducerImpl()
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
    
    var noAuthHttpClient: Ktor_client_coreHttpClient{
        return HttpClientProvider().provideNoAuth()
    }
    
    var authHttpClient: Ktor_client_coreHttpClient {
        return HttpClientProvider().provideAuth(authProvider: authProvider)
    }
    
    
}

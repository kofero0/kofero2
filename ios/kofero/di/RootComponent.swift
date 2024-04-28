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
        return "https://kofero.org"
    }
    
    var bannerAdUnitId: String {
        return "ca-app-pub-8614671926563443/4610731994"
    }
    
    //MARK: ROOT
    
    var rootView: RootView {
        return RootView(interactor: rootInteractor, homeView: homeView, gameView: gameView, charView: charView)
    }
    
    var rootPresenter: RootPresenter {
        return RootPresenterImpl(statusProvider: statusProvider, authProvider: authProvider, gameProvider: gameProvider, charProvider: charProvider, moveProvider: moveProvider, loggingProvider: loggingProvider)
    }
    
    var rootInteractor: RootInteractor{
        return RootInteractorImpl(presenter: rootPresenter, stateLogger: stateLogger, stateReducer: StateReducerImpl(), loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider)
    }
    
    //MARK: HOME
    
    var homePresenter: HomePresenter {
        return HomePresenterImpl(copyProvider: copyProvider, gameProvider: gameProvider, imageProvider: imageProvider, favoritesProvider: favoritesProvider, loggingProvider: loggingProvider)
    }
    
    var homeInteractor: HomeInteractor {
        return HomeInteractorImpl(presenter: homePresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
    }
    
    var homeView: HomeView{
        return HomeView(homeInteractor: homeInteractor, gameInteractor: gameInteractor, charInteractor: charInteractor, adUnitId: bannerAdUnitId)
    }
    
    //MARK: GAME
    
    var gameProvider: ProviderAbstract<ModelGame> {
        return shared { GameProviderImpl(client: authHttpClient, jsonFilename: "game", urlPrefix: urlPrefix, mapper: gameMapper, requestMapper: requestMapper, diskAccessor: diskAccessor) }
    }
    
    var gameMapper: GameMapperImpl {
        return shared { GameMapperImpl(encoder: jsonEncoder) }
    }
    
    var gamePresenter: GamePresenter {
        return shared { GamePresenterImpl(characterProvider: charProvider, gameProvider: gameProvider, imageProvider: imageProvider, loggingProvider: loggingProvider) }
    }
    
    var gameInteractor: GameInteractor {
        return shared { GameInteractorImpl(presenter: gamePresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
        }
    }
    
    var gameView: GameView {
        return shared { GameView(charInteractor: charInteractor, gameInteractor: gameInteractor, favProvider: favoritesProvider, adUnitId: bannerAdUnitId) }
    }
    
    //MARK: CHARACTER
    
    var charProvider: ProviderAbstract<ModelCharacter> {
        return CharProviderImpl(client: authHttpClient, jsonFilename: "char", urlPrefix: urlPrefix, mapper: charMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
    }
    
    var charMapper: CharacterMapperImpl {
        return CharacterMapperImpl(encoder: jsonEncoder)
    }
    
    var charPresenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: charProvider, moveProvider: moveProvider, imageProvider: imageProvider)
    }
    
    var charInteractor: CharacterInteractor {
        return shared { CharacterInteractorImpl(presenter: charPresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_) }
    }
    
    var charView: CharView {
        return CharView(interactor: charInteractor, favoritesProvider: favoritesProvider, gameProvider: gameProvider, adUnitId: bannerAdUnitId)
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

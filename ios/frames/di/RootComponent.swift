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
    
    //MARK: ROOT
    
    var rootView: RootView {
        return RootView(interactor: rootInteractor, homeView: homeView, gameView: gameView, charView: charView, searchView: searchView)
    }
    
    var rootPresenter: RootPresenter {
        return RootPresenterImpl(statusProvider: statusProvider, authProvider: authProvider, gameProvider: gameProvider, charProvider: charProvider, moveProvider: moveProvider, loggingProvider: loggingProvider)
    }
    
    var rootInteractor: RootInteractor{
        return RootInteractorImpl(presenter: rootPresenter, stateLogger: stateLogger, stateReducer: StateReducerImpl(), loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider)
    }
    
    //MARK: HOME
    
//    var homeComponent: HomeComponent{
//        return HomeComponent(copyProvider: copyProvider, gameProvider: gameComponent.gameProvider, imageProvider: imageProvider, favoritesProvider: favoritesProvider, loggingProvider: loggingProvider, stateLogger: stateLogger, stateReducer: stateReducer, dispatcherProvider: dispatcherProvider, gameInteractor: gameComponent.gameInteractor, charInteractor: characterComponent.charInteractor)
//    }
    
    var homePresenter: HomePresenter {
        return HomePresenterImpl(copyProvider: copyProvider, gameProvider: gameProvider, imageProvider: imageProvider, favoritesProvider: favoritesProvider, loggingProvider: loggingProvider)
        
    }
    
    var homeInteractor: HomeInteractor {
        return HomeInteractorImpl(presenter: homePresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
    }
    
    var homeView: HomeView{
        return HomeView(homeInteractor: homeInteractor, gameInteractor: gameInteractor, charInteractor: charInteractor)
    }
    
    //MARK: GAME
    
//    var gameComponent: GameComponent {
//        return GameComponent(authHttpClient: authHttpClient, urlPrefix: urlPrefix, requestMapper: requestMapper, diskAccessor: diskAccessor, jsonEncoder: jsonEncoder, charProvider: characterComponent.charProvider, imageProvider: imageProvider, loggingProvider: loggingProvider, stateLogger: stateLogger, stateReducer: stateReducer, dispatcherProvider: dispatcherProvider, charInteractor: characterComponent.charInteractor, favoritesProvider: favoritesProvider, queryMapper: queryMapper)
//    }
    
    private var _gameProvider: ProviderAbstract<ModelGame>? = nil
    
    var gameProvider: ProviderAbstract<ModelGame> {
        if(_gameProvider == nil){
            _gameProvider = GameProviderImpl(client: authHttpClient, jsonFilename: "game", urlPrefix: urlPrefix, mapper: gameMapper, queryMapper: queryMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
        }
        return _gameProvider!
    }
    
    private var _gameMapper: GameMapperImpl? = nil
    
    var gameMapper: GameMapperImpl {
        if(_gameMapper == nil){
            _gameMapper =  GameMapperImpl(encoder: jsonEncoder)
        }
        return _gameMapper!
    }
    
    private var _gamePresenter: GamePresenter? = nil
    
    var gamePresenter: GamePresenter {
        if(_gamePresenter == nil){
            _gamePresenter = GamePresenterImpl(characterProvider: charProvider, gameProvider: gameProvider, imageProvider: imageProvider, loggingProvider: loggingProvider)
        }
        return _gamePresenter!
    }
    
    private var _gameInteractor: GameInteractor? = nil
    
    var gameInteractor: GameInteractor {
        if(_gameInteractor == nil){
            _gameInteractor = GameInteractorImpl(presenter: gamePresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
        }
        return _gameInteractor!
    }
    
    private var _gameView: GameView? = nil
    
    var gameView: GameView {
        if(_gameView == nil){
           _gameView = GameView(charInteractor: charInteractor, gameInteractor: gameInteractor, favProvider: favoritesProvider)
        }
        return _gameView!
    }
    
    
    //MARK: CHARACTER
    
//    var characterComponent: CharacterComponent {
//        return CharacterComponent(authHttpClient: authHttpClient, urlPrefix: urlPrefix, requestMapper: requestMapper, diskAccessor: diskAccessor, jsonEncoder: jsonEncoder, imageProvider: imageProvider, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider, favoritesProvider: favoritesProvider, gameProvider: gameComponent.gameProvider, moveProvider: moveProvider, queryMapper: queryMapper)
//    }
    
    private var _charProvider: ProviderAbstract<ModelCharacter>? = nil
    
    var charProvider: ProviderAbstract<ModelCharacter> {
        if(_charProvider == nil){
            _charProvider = CharProviderImpl(client: authHttpClient, jsonFilename: "char", urlPrefix: urlPrefix, mapper: charMapper, queryMapper: queryMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
        }
        return _charProvider!
    }
    
    var charMapper: CharacterMapperImpl {
        return CharacterMapperImpl(encoder: jsonEncoder)
    }
    
    var charPresenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: charProvider, moveProvider: moveProvider, imageProvider: imageProvider)
    }
    
    private var _charInteractor: CharacterInteractor? = nil
    
    var charInteractor: CharacterInteractor {
        if(_charInteractor == nil){
            _charInteractor = CharacterInteractorImpl(presenter: charPresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
        }
        return _charInteractor!
    }
    
    var charView: CharView {
        return CharView(interactor: charInteractor, favoritesProvider: favoritesProvider, gameProvider: gameProvider)
    }
    
    //MARK: SEARCH
    
    var searchInteractor: SearchInteractor {
        return SearchInteractorImpl(presenter: searchPresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, dispatcherProvider: dispatcherProvider)
    }
    
    var searchPresenter: SearchPresenter {
        return SearchPresenterImpl(gameProvider: gameProvider, charProvider: charProvider, loggingProvider: loggingProvider)
    }
    
    var searchView: SearchView {
        return SearchView(searchInteractor: searchInteractor, gameInteractor: gameInteractor, charInteractor: charInteractor)
    }
    
    //MARK: MOVE
    
    private var _moveProvider: ProviderAbstract<ModelMove>? = nil
    
    var moveProvider: ProviderAbstract<ModelMove> {
        if(_moveProvider == nil){
            _moveProvider = MoveProviderImpl(client: authHttpClient, jsonFilename: "move", urlPrefix: urlPrefix, mapper: moveMapper, queryMapper: queryMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
        }
        return _moveProvider!
    }
    
    var moveMapper:MoveMapper{
        return MoveMapperImpl(encoder: jsonEncoder)
    }
    
    //MARK: PROVIDER
    
    var queryMapper: QueryMapper {
        return QueryMapperImpl()
    }
    
    var dispatcherProvider: DispatcherProvider {
        return DispatcherProvider()
    }
    
    var statusProvider: StatusProvider {
        return StatusProviderImpl(client: authHttpClient, urlPrefix: urlPrefix, mapper: statusMapper, diskAccessor: diskAccessor)
    }
    
    var copyProvider: CopyProvider {
        return CopyProviderImpl(client: authHttpClient, jsonFilename: "copy", urlPrefix: urlPrefix, mapper: CopyMapperImpl(), diskAccessor: diskAccessor)
    }
    
    private var _authProvider: AuthProvider? = nil
    
    var authProvider: AuthProvider {
        if(_authProvider == nil){
            _authProvider = AuthProviderImpl(client: noAuthHttpClient, urlPrefix: urlPrefix, diskAccessor: AuthDiskAccessorImpl(), authMapper: AuthMapperImpl(), identityProvider: identityProvider)
        }
        return _authProvider!
    }
    
    var identityProvider: IdentityProvider{
        return IdentityProviderImpl()
    }
    
    private var _favoritesProvider: FavoritesProvider? = nil
    
    var favoritesProvider:FavoritesProvider {
        if(_favoritesProvider == nil){
            _favoritesProvider = FavoritesProviderImpl(loggingProvider: loggingProvider, diskAccessor: diskAccessor, mapper: FavoritesMapper(encoder: jsonEncoder, gameMapper: gameMapper, charMapper: charMapper))
        }
        return _favoritesProvider!
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
    
    private var _noAuthHttpClient: Ktor_client_coreHttpClient? = nil
    
    var noAuthHttpClient: Ktor_client_coreHttpClient{
        if(_noAuthHttpClient == nil){
            _noAuthHttpClient = HttpClientProvider().provideNoAuth()
        }
        return _noAuthHttpClient!
    }
    
    private var _authHttpClient: Ktor_client_coreHttpClient? = nil
    
    var authHttpClient: Ktor_client_coreHttpClient {
        if(_authHttpClient == nil){
            _authHttpClient = HttpClientProvider().provideAuth(authProvider: authProvider)
        }
        return _authHttpClient!
    }
}

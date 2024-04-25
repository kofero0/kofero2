//
//  GameComponent.swift
//  FRAMES
//
//  Created by Mitch Drew on 19.04.2024.
//

import Foundation
import presenter
import SwiftyJSON

class GameComponent {
    private let authHttpClient: Ktor_client_coreHttpClient
    private let urlPrefix: String
    private let requestMapper: RequestMapper
    private let diskAccessor: DiskAccessor
    private let jsonEncoder: StringEncoder<[JSON]>
    private let charProvider: ProviderAbstract<ModelCharacter>
    private let imageProvider: ImageProvider
    private let loggingProvider: LoggingProvider
    private let stateLogger: StateLogger
    private let stateReducer: StateReducer
    private let dispatcherProvider: DispatcherProvider
    private let charInteractor: CharacterInteractor
    private let favoritesProvider: FavoritesProvider
    private let queryMapper: QueryMapper
    
    init(authHttpClient: Ktor_client_coreHttpClient, urlPrefix: String, requestMapper: RequestMapper, diskAccessor: DiskAccessor, jsonEncoder: StringEncoder<[JSON]>, charProvider: ProviderAbstract<ModelCharacter>, imageProvider: ImageProvider, loggingProvider: LoggingProvider, stateLogger: StateLogger, stateReducer: StateReducer, dispatcherProvider: DispatcherProvider, charInteractor: CharacterInteractor, favoritesProvider: FavoritesProvider, queryMapper: QueryMapper) {
        self.authHttpClient = authHttpClient
        self.urlPrefix = urlPrefix
        self.requestMapper = requestMapper
        self.diskAccessor = diskAccessor
        self.jsonEncoder = jsonEncoder
        self.charProvider = charProvider
        self.imageProvider = imageProvider
        self.loggingProvider = loggingProvider
        self.stateLogger = stateLogger
        self.stateReducer = stateReducer
        self.dispatcherProvider = dispatcherProvider
        self.charInteractor = charInteractor
        self.favoritesProvider = favoritesProvider
        self.queryMapper = queryMapper
    }
    
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
}

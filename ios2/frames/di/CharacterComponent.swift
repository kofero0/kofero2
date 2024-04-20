//
//  CharacterComponent.swift
//  FRAMES
//
//  Created by Mitch Drew on 20.04.2024.
//

import Foundation
import presenter
import SwiftyJSON

class CharacterComponent {
    private let authHttpClient: Ktor_client_coreHttpClient
    private let urlPrefix: String
    private let requestMapper: RequestMapper
    private let diskAccessor: DiskAccessor
    private let jsonEncoder: StringEncoder<[JSON]>
    private let imageProvider: ImageProvider
    private let stateLogger: StateLogger
    private let stateReducer: StateReducer
    private let loggingProvider: LoggingProvider
    private let dispatcherProvider: DispatcherProvider
    private let favoritesProvider: FavoritesProvider
    private let gameProvider: ProviderAbstract<ModelGame>
    private let moveProvider: ProviderAbstract<ModelMove>
    
    init(authHttpClient: Ktor_client_coreHttpClient, urlPrefix:String, requestMapper: RequestMapper, diskAccessor: DiskAccessor, jsonEncoder: StringEncoder<[JSON]>, imageProvider: ImageProvider, stateLogger: StateLogger, stateReducer: StateReducer, loggingProvider: LoggingProvider, dispatcherProvider: DispatcherProvider, favoritesProvider: FavoritesProvider, gameProvider: ProviderAbstract<ModelGame>, moveProvider: ProviderAbstract<ModelMove>) {
        self.urlPrefix = urlPrefix
        self.authHttpClient = authHttpClient
        self.requestMapper = requestMapper
        self.diskAccessor = diskAccessor
        self.jsonEncoder = jsonEncoder
        self.imageProvider = imageProvider
        self.stateLogger = stateLogger
        self.stateReducer = stateReducer
        self.loggingProvider = loggingProvider
        self.dispatcherProvider = dispatcherProvider
        self.favoritesProvider = favoritesProvider
        self.gameProvider = gameProvider
        self.moveProvider = moveProvider
    }
    
    var charProvider: ProviderAbstract<ModelCharacter> {
        return CharProviderImpl(client: authHttpClient, jsonFilename: "char", urlPrefix: urlPrefix, mapper: charMapper, requestMapper: requestMapper, diskAccessor: diskAccessor)
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
}

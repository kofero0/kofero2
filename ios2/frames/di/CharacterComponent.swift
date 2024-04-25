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
    private let queryMapper: QueryMapper
    
    init(authHttpClient: Ktor_client_coreHttpClient, urlPrefix:String, requestMapper: RequestMapper, diskAccessor: DiskAccessor, jsonEncoder: StringEncoder<[JSON]>, imageProvider: ImageProvider, stateLogger: StateLogger, stateReducer: StateReducer, loggingProvider: LoggingProvider, dispatcherProvider: DispatcherProvider, favoritesProvider: FavoritesProvider, gameProvider: ProviderAbstract<ModelGame>, moveProvider: ProviderAbstract<ModelMove>, queryMapper: QueryMapper) {
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
        self.queryMapper = queryMapper
    }
    
    
}

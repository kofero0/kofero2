//
//  HomeComponent.swift
//  FRAMES
//
//  Created by Mitch Drew on 19.04.2024.
//

import Foundation
import presenter

class HomeComponent {
    private let copyProvider: CopyProvider
    private let gameProvider: ProviderAbstract<ModelGame>
    private let imageProvider: ImageProvider
    private let favoritesProvider: FavoritesProvider
    private let loggingProvider: LoggingProvider
    private let stateLogger: StateLogger
    private let stateReducer: StateReducer
    private let dispatcherProvider: DispatcherProvider
    private let gameInteractor: GameInteractor
    private let charInteractor: CharacterInteractor
    
    init(copyProvider: CopyProvider, gameProvider: ProviderAbstract<ModelGame>, imageProvider: ImageProvider, favoritesProvider: FavoritesProvider, loggingProvider: LoggingProvider, stateLogger: StateLogger, stateReducer: StateReducer, dispatcherProvider: DispatcherProvider, gameInteractor: GameInteractor, charInteractor: CharacterInteractor) {
        self.copyProvider = copyProvider
        self.gameProvider = gameProvider
        self.imageProvider = imageProvider
        self.favoritesProvider = favoritesProvider
        self.loggingProvider = loggingProvider
        self.stateLogger = stateLogger
        self.stateReducer = stateReducer
        self.dispatcherProvider = dispatcherProvider
        self.gameInteractor = gameInteractor
        self.charInteractor = charInteractor
    }
    
    var homePresenter: HomePresenter {
        return HomePresenterImpl(copyProvider: copyProvider, gameProvider: gameProvider, imageProvider: imageProvider, favoritesProvider: favoritesProvider, loggingProvider: loggingProvider)
        
    }
    
    var homeInteractor: HomeInteractor {
        return HomeInteractorImpl(presenter: homePresenter, stateLogger: stateLogger, stateReducer: stateReducer, loggingProvider: loggingProvider, context: dispatcherProvider.default_)
    }
    
    var homeView: HomeView{
        return HomeView(homeInteractor: homeInteractor, gameInteractor: gameInteractor, charInteractor: charInteractor)
    }
}

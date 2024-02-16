//
//  HomeComponent.swift
//  debug
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftUI

protocol HomeDependency: Dependency {
    var bannerAdUnitId:String {get}
    var gameProvider:ProviderAbstract<ModelGame> {get}
    var charProvider:ProviderAbstract<ModelCharacter> {get}
    var imageProvider:ImageProvider {get}
    var favoritesProvider:FavoritesProvider {get}
    var stateLogger:StateLogger {get}
    var stateReducer:StateReducer {get}
    var loggingProvider:LoggingProvider {get}
    var dispatcherProvider: DispatcherProvider {get}
    var gameInteractor: GameInteractor {get}
    var charInteractor: CharacterInteractor {get}
}

class HomeComponent: Component<HomeDependency> {
    
    var presenter: HomePresenter {
        return HomePresenterImpl(gameProvider: dependency.gameProvider, imageProvider: dependency.imageProvider, favoritesProvider: dependency.favoritesProvider, loggingProvider: dependency.loggingProvider)
    }
    
    var interactor: HomeInteractor {
        return HomeInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, context: dependency.dispatcherProvider.default_)
    }
    
    var homeView: HomeView{
        return HomeView(homeInteractor: interactor, gameInteractor: dependency.gameInteractor, charInteractor: dependency.charInteractor, adUnitId: dependency.bannerAdUnitId)
    }
}

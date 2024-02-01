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
    var gameView: GameView {get}
    var charView: CharView {get}
}

class HomeComponent: Component<HomeDependency> {
    
    var presenter: HomePresenter {
        return HomePresenterImpl(gameProvider: dependency.gameProvider, charProvider: dependency.charProvider, imageProvider: dependency.imageProvider, favoritesProvider: dependency.favoritesProvider, loggingProvider: dependency.loggingProvider)
    }
    
    var interactor: HomeInteractor {
        return HomeInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, context: dependency.dispatcherProvider.default_)
    }
    
    var homeView: HomeView{
        return HomeView(interactor: interactor, adUnitId: dependency.bannerAdUnitId, gameView: dependency.gameView, charView: dependency.charView)
    }
}

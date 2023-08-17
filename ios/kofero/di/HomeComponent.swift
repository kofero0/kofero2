//
//  HomeComponent.swift
//  debug
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import NeedleFoundation
import presenter

protocol HomeDependency: Dependency {
    var bannerAdUnitId:String {get}
    var gameProvider:GameProvider {get}
    var gameViewBuilder:GameViewBuilder {get}
    var imageProvider:ImageProvider {get}
    var favoritesProvider:FavoritesProvider {get}
    var stateLogger:StateLogger {get}
    var stateReducer:StateReducer {get}
    var loggingProvider:LoggingProvider {get}
    var uiApplication:UIApplication {get}
    var dispatcherProvider: DispatcherProvider {get}
}

class HomeComponent: Component<HomeDependency>, HomeViewBuilder {
    
    var presenter: HomePresenter {
        return HomePresenterImpl(gameProvider: dependency.gameProvider, imageProvider: dependency.imageProvider, favoritesProvider: dependency.favoritesProvider, loggingProvider: dependency.loggingProvider)
    }
    
    var interactor: HomeInteractor {
        return HomeInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, router: router, context: dependency.dispatcherProvider.default_)
    }
    
    var router: Router {
        return HomeRouter(dependency.gameViewBuilder, dependency.uiApplication)
    }
    
    func homeView() -> View {
        return HomeView(interactor: interactor, adUnitId: dependency.bannerAdUnitId)
    }
}

protocol HomeViewBuilder {
    func homeView() -> View
}

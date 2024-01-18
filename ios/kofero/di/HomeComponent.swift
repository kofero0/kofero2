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
    var gameProvider:GameProvider {get}
    var charProvider:CharacterProvider {get}
    var gameViewBuilder:GameViewBuilder {get}
    var imageProvider:ImageProvider {get}
    var favoritesProvider:FavoritesProvider {get}
    var stateLogger:StateLogger {get}
    var stateReducer:StateReducer {get}
    var loggingProvider:LoggingProvider {get}
    var navController:UINavigationController {get}
    var dispatcherProvider: DispatcherProvider {get}
}

class HomeComponent: Component<HomeDependency>, HomeViewBuilder {
    
    var presenter: HomePresenter {
        return HomePresenterImpl(gameProvider: dependency.gameProvider, charProvider: dependency.charProvider, imageProvider: dependency.imageProvider, favoritesProvider: dependency.favoritesProvider, loggingProvider: dependency.loggingProvider)
    }
    
    var interactor: HomeInteractor {
        return HomeInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, router: router, context: dependency.dispatcherProvider.default_)
    }
    
    var router: HomeRouter {
        return HomeRouterImpl(dependency.gameViewBuilder, navController: dependency.navController)
    }
    
    func homeView() -> AnyView {
        return AnyView(HomeView(interactor: interactor, adUnitId: dependency.bannerAdUnitId))
    }
}

protocol HomeViewBuilder {
    func homeView() -> AnyView
}

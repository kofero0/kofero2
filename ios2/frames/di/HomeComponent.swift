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
    var copyProvider: CopyProvider {get}
}

class HomeComponent: Component<HomeDependency> {
    
}

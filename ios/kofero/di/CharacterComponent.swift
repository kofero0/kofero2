//
//  CharacterComponent.swift
//  debug
//
//  Created by Mitchell Drew on 11/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftUI
import SwiftyJSON

protocol CharacterDependency: Dependency {
    var moveProvider: MoveProvider {get}
    var imageProvider: ImageProvider {get}
    var providerCore:ProviderCore {get}
    var jsonEncoder:DataEncoder<[JSON]> {get}
    var bannerAdUnitId: String {get}
    var loggingProvider: LoggingProvider {get}
    var stateLogger: StateLogger {get}
    var stateReducer: StateReducer {get}
    var dispatcherProvider: DispatcherProvider {get}
}

class CharacterComponent: Component<CharacterDependency>, CharViewBuilder {
    var provider: CharacterProvider {
        return ProviderImpl(core: dependency.providerCore, url: url, mapper: mapper, jsonFilename: jsonFilename, loggingProvider: dependency.loggingProvider) as! CharacterProvider
    }
    
    var jsonFilename:String {
        return "char"
    }
    
    var url: URL {
        return URL(string: "https://google.com")!
    }
    
    var mapper: DataMapper<[ModelCharacter]> {
        return CharacterMapper(encoder: dependency.jsonEncoder)
    }
    
    var presenter: CharacterPresenter {
        return CharacterPresenterImpl(charProvider: provider, moveProvider: dependency.moveProvider, imageProvider: dependency.imageProvider)
    }
    
    var interactor: CharacterInteractor {
        return CharacterInteractorImpl(presenter: presenter, stateLogger: dependency.stateLogger, stateReducer: dependency.stateReducer, loggingProvider: dependency.loggingProvider, router: router, context: dependency.dispatcherProvider.default_)
    }
    
    var router: Router {
        return CharRouter()
    }
    
    func characterView(id:Int32) -> AnyView {
        return AnyView(CharView(charId: id, interactor: interactor, adUnitId: dependency.bannerAdUnitId))
    }
}

protocol CharViewBuilder {
    func characterView(id:Int32) -> AnyView
}

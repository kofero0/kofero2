//
//  CharacterComponent.swift
//  debug
//
//  Created by Mitchell Drew on 11/3/21.
//

import Foundation
import NeedleFoundation
import presenter
import SwiftyJSON

protocol CharacterDependency: Dependency {
    var moveProvider: MoveProvider {get}
    var imageProvider: ImageProvider {get}
    var providerCore:ProviderCore {get}
    var jsonEncoder:DataEncoder<[JSON]> {get}
    var moveViewBuilder:MoveViewBuilder {get}
    var bannerAdUnitId: String {get}
    var loggingProvider: LoggingProvider {get}
}

class CharacterComponent: Component<CharacterDependency>, CharacterViewBuilder {
    var provider: CharacterProvider {
        return Provider(core: dependency.providerCore, url: url, mapper: mapper, jsonFilename: jsonFilename, loggingProvider: dependency.loggingProvider) as! CharacterProvider
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
    
    func characterView(id:Int32) -> UIViewController {
        return CharacterView(presenter: presenter, charId: id, moveViewBuilder: dependency.moveViewBuilder, adUnitId: dependency.bannerAdUnitId)
    }
}

protocol CharacterViewBuilder {
    func characterView(id:Int32) -> UIViewController
}

//
//  MoveComponent.swift
//  debug
//
//  Created by Mitchell Drew on 12/3/21.
//

import Foundation
import presenter
import SwiftyJSON
import NeedleFoundation

protocol MoveDependency: Dependency {
    var providerCore:ProviderCore {get}
    var jsonEncoder:DataEncoder<[JSON]> {get}
    var loggingProvider:LoggingProvider {get}
}

class MoveComponent: Component<MoveDependency> {
    var provider: MoveProvider {
        return ProviderImpl(core: dependency.providerCore, url: url, mapper: mapper, jsonFilename: jsonFilename, loggingProvider: dependency.loggingProvider) as! MoveProvider
    }
    
    var jsonFilename:String {
        return "move"
    }
    
    var mapper:DataMapper<[ModelMove]>{
        return MoveMapper(encoder: dependency.jsonEncoder)
    }
    
    var url:URL {
        return URL(string: "https://google.com")!
    }
}

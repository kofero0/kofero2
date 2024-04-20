//
//  Router.swift
//  kofero
//
//  Created by Mitchell Drew on 28/1/24.
//

import Foundation


enum Route: Equatable {
    case Home
    case Game
    case Char
    case Search
}

class Router<Route: Equatable>: ObservableObject {
    var routes = [Route]()
    var onPush: ((Route) -> Void)?
    var onPop: (() -> Void)?
    
    init(initial: Route? = nil) {
        if let initial = initial {
            routes.append(initial)
        }
    }
    
    func pop() {
        routes.removeLast()
        onPop?()
    }
    
    func push(_ route: Route) {
        routes.append(route)
        onPush?(route)
    }
}

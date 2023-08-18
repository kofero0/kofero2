//
//  GameRouter.swift
//  kofero
//
//  Created by Mitchell Drew on 17/8/23.
//

import Foundation
import presenter
import UIKit

class GameRouter: Router {
    let charViewBuilder: CharViewBuilder
    let navController: UINavigationController
    
    public init(_ charViewBuilder:CharViewBuilder, navController:UINavigationController){
        self.navController = navController
        self.charViewBuilder = charViewBuilder
    }
    
    func routeTo(view: ModelEvent.ViewTag, uid: Int32) -> Bool {
        if(view != .charView){ return false }
        navController.present(charViewBuilder.characterView(id: uid))
        return view == .charView
    }
}

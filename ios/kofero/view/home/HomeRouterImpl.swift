//
//  HomeRouter.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import Foundation
import presenter
import SwiftUI

class HomeRouterImpl: HomeRouter {
    let gameViewBuilder: GameViewBuilder
    let navController: UINavigationController
    
    public init(_ gameViewBuilder:GameViewBuilder, navController:UINavigationController){
        self.navController = navController
        self.gameViewBuilder = gameViewBuilder
    }
    
    
    func routeTo(view: ModelViewTag, uid: Int32) -> Bool {
        if(view != .gameView){ return false }
        navController.present(gameViewBuilder.gameView(id: uid))
        return view == .gameView
    }
}

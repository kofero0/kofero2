//
//  RootRouter.swift
//  kofero
//
//  Created by Mitchell Drew on 24/1/24.
//

import Foundation
import presenter

class RootRouterImpl: RootRouter {
    func routeTo(view: ModelViewTag, uid: Int32) -> Bool {
        print("@@@@ROOT ROUTER routeTo CALLED@@@@@")
        return true
    }
}

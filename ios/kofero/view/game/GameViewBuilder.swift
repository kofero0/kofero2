//
//  GameViewBuilder.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import Foundation
import SwiftUI

protocol GameViewBuilder{
    func gameView(id:Int32) -> AnyView
}

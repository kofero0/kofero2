//
//  File.swift
//  FRAMES
//
//  Created by Mitch Drew on 18.04.2024.
//

import Foundation
import SwiftUI
import presenter

struct SearchView: View {
    private let searchInteractor: SearchInteractor
    private let gameInteractor: GameInteractor
    private let charInteractor: CharacterInteractor
    
    init(searchInteractor: SearchInteractor, gameInteractor: GameInteractor, charInteractor: CharacterInteractor){
        self.searchInteractor = searchInteractor
        self.gameInteractor = gameInteractor
        self.charInteractor = charInteractor
    }
    
    var body: some View{
        ScrollView{
            LazyVGrid(columns:[], spacing: 20){
                
            }
        }
    }
}

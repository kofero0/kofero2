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
    
    @State private var name: String = "Tim"
    
    init(searchInteractor: SearchInteractor, gameInteractor: GameInteractor, charInteractor: CharacterInteractor){
        self.searchInteractor = searchInteractor
        self.gameInteractor = gameInteractor
        self.charInteractor = charInteractor
    }
    
    var micClosure: (() -> Void) {
        return {
            
        }
    }
    
    var searchClosure: (() -> Void) {
        return {
            
        }
    }
    
    var body: some View{
        VStack{
            HStack{
                TextField("Search Here", text: $name)
                Image("mic")
                    .resizable()
                    .frame(width: 50, height: 50)
                    .onTapGesture {
                        
                    }
                Image("magnifyingglass")
                    .resizable()
                    .frame(width: 50, height: 50)
                    .onTapGesture {
                        
                    }
            }
            ScrollView{
                LazyVGrid(columns:[], spacing: 20){
                    
                }
            }
        }
        .navigationTitle("Search")
    }
}

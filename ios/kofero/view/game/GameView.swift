//
//  GameView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

enum GameRoute:Equatable {
    case Game
    case Char
}

struct GameView: View {
    let adUnitId:String
    let interactor: GameInteractor
    let charView: CharView
    @StateObject var viewModel = GameViewModel()
    @StateObject var router: Router<GameRoute> = Router(initial: .Game)
    
    
    init(charView:CharView, interactor:GameInteractor, adUnitId:String){
        self.charView = charView
        self.adUnitId = adUnitId
        self.interactor = interactor
        interactor.setView(view: viewModel)
    }
    
    
    var body: some View {
        RouterHost(router: router) { route in
            switch route {
            case .Game: gameView
            case .Char: charView
            }
        }
    }
    
    var gameView: some View {
        VStack{
            
        }
    }
    
    class GameViewModel: ObservableObject, GameKView {
        @Published var game: ModelGame? = nil
        @Published var chars: [ModelCharacter] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        
        func display(url: String, imgBase64: String) {
            urlsToImages[url]=imgBase64
        }
        
        func display(characters: [ModelCharacter]) {
            chars = characters
        }
        
        func display(game: ModelGame) {
            self.game = game
        }
        
        func displayCharsError(error: ModelError) {
            lastError = error
        }
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func display(url: String, imgBase64: String) async throws {
            urlsToImages[url] = imgBase64
        }
        
        func displayGameError(error: ModelError) {
        }
    }
}

//
//  GameView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct GameView: View {
    let gameId:Int32
    let adUnitId:String
    let interactor: GameInteractor
    @StateObject var viewModel = GameViewModel()
    
    
    init(gameId:Int32, interactor:GameInteractor, adUnitId:String){
        self.gameId = gameId
        self.adUnitId = adUnitId
        self.interactor = interactor
        interactor.setView(view: viewModel)
    }
    
    
    var body: some View {
        Text(/*@START_MENU_TOKEN@*/"Hello, World!"/*@END_MENU_TOKEN@*/)
    }
    
    class GameViewModel: ObservableObject, GameKView {
        func displayGameError(error: ModelError) {
            <#code#>
        }
        
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
        
        
    }
}

struct GameView_Previews: PreviewProvider {
    static var previews: some View {
        GameView(gameId: 0, interactor: MockGameInteractor(), adUnitId: "mock")
    }
}

class MockGameInteractor: GameInteractor {
    func setGameUid(uid: Int32) async throws {
        <#code#>
    }
    
    func charPressed(char char_: ModelCharacter) {
    }
    
    func setGameUid(uid: Int32) {
    }
    
    func setView(view: KView) {
    }
    
    func shutdown() {
    }
    
    func viewPaused() {
    }
    
    func viewResumed() {
    }
}

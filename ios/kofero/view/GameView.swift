//
//  GameView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct GameView: View {
    let adUnitId:String
    let gameInteractor: GameInteractor
    let charInteractor: CharacterInteractor
    @StateObject var viewModel = GameViewModel()
    @EnvironmentObject var router: Router<Route>
    
    
    init(charInteractor:CharacterInteractor, gameInteractor:GameInteractor, adUnitId:String){
        self.charInteractor = charInteractor
        self.gameInteractor = gameInteractor
        self.adUnitId = adUnitId
    }
    
    
    var charClosure: ((ModelCharacter) -> Void) {
        return { char in
            gameInteractor.charPressed(char: char){_ in}
            charInteractor.setCharUid(uid: char.uid){_ in}
            router.push(.Char)
        }
    }
    
    
    var body: some View {
        VStack{
        ScrollView {
            LazyVGrid(columns: [
                GridItem(.flexible()),
                GridItem(.flexible()),
                GridItem(.flexible())
            ], spacing: 20) {
                ForEach(viewModel.chars, id: \.self) { char in
                    VStack{
                        Image(uiImage: convertBase64StringToImage(imageBase64String: viewModel.urlsToImages[char.iconUrl] ?? nil))
                        Text(char.name)
                    }.onTapGesture {
                        charClosure(char)
                    }
                }
            }
        }
        }.onAppear{
            gameInteractor.setView(view: viewModel)
            gameInteractor.viewResumed()
        }
        .onDisappear{
            gameInteractor.viewPaused()
        }
        .navigationTitle(viewModel.game?.name ?? "")
    }
    
    class GameViewModel: ObservableObject, GameKView {
        @Published var game: ModelGame? = nil
        @Published var chars: [ModelCharacter] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        func display(characters: [ModelCharacter]) {
            DispatchQueue.main.sync {
                print("chars")
                print(characters)
                chars = characters
            }
        }
        
        func display(game: ModelGame) {
            DispatchQueue.main.sync {
                print("game")
                print(game)
                self.game = game
            }
        }
        
        func displayCharsError(error: ModelError) {
            lastError = error
        }
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        @MainActor func display(url: String, imgBase64: String) async throws {
            urlsToImages[url] = imgBase64
        }
        
        func displayGameError(error: ModelError) {
        }
    }
}

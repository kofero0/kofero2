//
//  GameView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct GameView: View {
    private let adUnitId:String
    private let gameInteractor: GameInteractor
    private let charInteractor: CharacterInteractor
    private let favProvider: FavoritesProvider
    @StateObject private var viewModel = GameViewModel()
    @EnvironmentObject var router: Router<Route>
    
    
    init(charInteractor:CharacterInteractor, gameInteractor:GameInteractor, favProvider: FavoritesProvider, adUnitId:String){
        self.charInteractor = charInteractor
        self.gameInteractor = gameInteractor
        self.favProvider = favProvider
        self.adUnitId = adUnitId
    }
    
    
    private var charClosure: ((ModelCharacter, ModelGame) -> Void) {
        return { char, game in
            gameInteractor.charPressed(char: char){_ in}
            charInteractor.setUids(charUid: char.uid, gameUid: game.uid){_ in}
            router.push(.Char)
        }
    }
    
    private var favClosure: ((ModelGame) -> Void) {
        return { game in
            if(viewModel.isFavorited){
                viewModel.favProvider?.delete(fav: ModelFavorite(game: game, character: nil)){_,_ in }
            } else{
                viewModel.favProvider?.save(fav: ModelFavorite(game: game, character: nil)){_,_ in }
            }
            viewModel.isFavorited = !(viewModel.isFavorited)
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
                        charClosure(char, viewModel.game!)
                    }
                }
            }
        }
        }.onAppear{
            gameInteractor.setView(view: viewModel)
            viewModel.favProvider = favProvider
            gameInteractor.viewResumed()
        }
        .onDisappear{
            gameInteractor.viewPaused()
        }
        .navigationTitle(viewModel.game?.name ?? "")
        .toolbar{
            Button(action: {
                if let uGame = viewModel.game {
                    favClosure(uGame)
                }
            }, label: {
                if(viewModel.isFavorited){
                    Image(systemName: "heart.fill")
                }
                else{
                    Image(systemName: "heart")
                }
            })
        }
    }
    
    private class GameViewModel: ObservableObject, GameKView {
        @Published var game: ModelGame? = nil
        @Published var chars: [ModelCharacter] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        @Published var isFavorited: Bool = false
        var favProvider: FavoritesProvider? = nil
        
        
        func display(characters: [ModelCharacter]) {
            DispatchQueue.main.sync {
                chars = characters
            }
        }
        
        func display(game: ModelGame) {
            DispatchQueue.main.sync {
                self.game = game
                favProvider?.get { either,error in
                    either?.map{ array in
                        if let uArray = array {
                            for ele in uArray{
                                if let fav = ele as? ModelFavorite{
                                    if(fav.game.uid == game.uid && fav.character == nil){
                                        DispatchQueue.main.sync {
                                            self.isFavorited = true
                                        }
                                    }
                                }
                            }
                        }
                        return NSObject()
                    }
                }
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

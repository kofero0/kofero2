//
//  HomeView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter
import Combine


struct HomeView: View {
    private let homeInteractor: HomeInteractor
    private let gameInteractor: GameInteractor
    private let charInteractor: CharacterInteractor
    
    let adUnitId: String
    @EnvironmentObject var router: Router<Route>
    @StateObject var viewModel = HomeViewModel()
    
    init(homeInteractor: HomeInteractor, gameInteractor: GameInteractor, charInteractor:CharacterInteractor, adUnitId: String){
        self.homeInteractor = homeInteractor
        self.gameInteractor = gameInteractor
        self.charInteractor = charInteractor
        self.adUnitId = adUnitId
    }
    
    var gameClosure: ((ModelGame) -> Void) {
        return { game in
            homeInteractor.gamePressed(game: game){_ in}
            gameInteractor.setGameUid(uid: game.uid){_ in}
            router.push(.Game)
        }
    }
    
    var charClosure: ((ModelCharacter) -> Void) {
        return { char in
            homeInteractor.favPressed(obj: char){_ in}
            charInteractor.setCharUid(uid: char.uid){_ in}
            router.push(.Char)
        }
    }
    
    var body: some View {
        ScrollView {
                LazyVGrid(columns: [
                    GridItem(.flexible()),
                    GridItem(.flexible()),
                    GridItem(.flexible())
                ], spacing: 20) {
                    ForEach(viewModel.games, id: \.self) { game in
                        VStack{
                            //Image(uiImage: convertBase64StringToImage(imageBase64String: viewModel.urlsToImages[game.iconUrl] ?? nil))
                            Text(game.name)
                        }.onTapGesture {
                            gameClosure(game)
                        }
                    }
                }
            }
        .onAppear{
            homeInteractor.setView(view: viewModel)
            homeInteractor.viewResumed()
        }
        .onDisappear{ homeInteractor.viewPaused() }
        .navigationTitle("Home")
    }
    
    class HomeViewModel: HomeKView, ObservableObject {
        @Published var games: [ModelGame] = []
        @Published var favs: [Any] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func displayFavs(favorites: [Any]) {
            DispatchQueue.main.sync {
                favs = favorites
            }
        }
        
        func displayFavsError(error: ModelError) {
            lastError = error
        }
        
        func displayGames(games: [ModelGame]) {
            DispatchQueue.main.sync {
                self.games = games
            }
        }
        
        func displayGamesError(error: ModelError) {
            lastError = error
        }
        
        @MainActor func display(url: String, imgBase64: String) async throws {
            print("#@#@")
            print(url)
                urlsToImages[url] = imgBase64
        }
    }
}



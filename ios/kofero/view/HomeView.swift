//
//  HomeView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter


enum HomeRoute: Equatable {
    case Home
    case Game
    case Char
}

struct HomeView: View {
    let interactor: HomeInteractor
    let gameView: GameView
    let charView: CharView
    
    let adUnitId: String
    @StateObject var router: Router<HomeRoute> = Router(initial: .Home)
    @StateObject var viewModel = HomeViewModel()
    
    init(interactor: HomeInteractor, adUnitId: String, gameView: GameView, charView:CharView){
        self.gameView = gameView
        self.charView = charView
        self.interactor = interactor
        self.adUnitId = adUnitId
        interactor.setView(view: viewModel)
    }
    
    
    var body: some View {
        RouterHost(router: router) { route in
            switch route {
            case .Home: homeView
            case .Game: gameView
            case .Char: charView
            }
        }.onAppear{ interactor.viewResumed() }
            .onDisappear{ interactor.viewPaused() }
    }
    
    var homeView: some View {
        VStack{
            Text("Favorites")
            //            LazyVGrid{
            //
            //            }
            Text("Games")
            //            LazyVGrid(columns: <#[GridItem]#>){
            //
            //            }
        }
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
            favs = favorites
        }
        
        func displayFavsError(error: ModelError) {
            lastError = error
        }
        
        func displayGames(games: [ModelGame]) {
            self.games = games
        }
        
        func displayGamesError(error: ModelError) {
            lastError = error
        }
        
        func display(url: String, imgBase64: String) async throws {
            urlsToImages[url] = imgBase64
        }
    }
}

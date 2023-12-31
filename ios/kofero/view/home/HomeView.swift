//
//  HomeView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct HomeView: View {
    let interactor: HomeInteractor
    let adUnitId: String
    @StateObject var viewModel = HomeViewModel()
    
    init(interactor: HomeInteractor, adUnitId: String){
        self.interactor = interactor
        self.adUnitId = adUnitId
        interactor.setView(view: viewModel)
    }
    
    
    var body: some View {
        Text(/*@START_MENU_TOKEN@*/"Hello, World!"/*@END_MENU_TOKEN@*/)
    }
    
    
    class HomeViewModel: HomeKView, ObservableObject {
        @Published var games: [ModelGame] = []
        @Published var favs: [ModelObj] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func display(url: String, imgBase64: String) {
            urlsToImages[url] = imgBase64
        }
        
        func displayFavs(favorites: [ModelObj]) {
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
    }
}

struct HomeView_Previews: PreviewProvider {
    static var previews: some View {
        HomeView(
            interactor: MockHomeInteractor(), adUnitId: "mock"
        )
    }
}



class MockHomeInteractor: HomeInteractor {
    
    func favPressed(obj: ModelObj) async throws {
    }
    
    func gamePressed(game: ModelGame) async throws {
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

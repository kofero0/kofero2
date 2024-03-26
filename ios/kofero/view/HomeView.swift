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
    
    var favClosure: ((ModelFavorite) -> Void) {
        return { fav in
            homeInteractor.favPressed(fav: fav){_ in}
            if(fav.character == nil){
                gameInteractor.setGameUid(uid: fav.game.uid){_ in}
                router.push(.Game)
            } else {
                charInteractor.setUids(charUid: fav.character!.uid, gameUid: fav.game.uid){_ in}
                router.push(.Char)
            }
        }
    }
    
    private func getGamesToShow(games: [ModelGame], favs : [ModelFavorite]) -> [ModelGame] {
        var ret = games
        for fav in favs {
            if(fav.character == nil) {
                ret.removeAll { element in return element.uid == fav.game.uid }
            }
        }
        return ret
    }
    
    var body: some View {
        ScrollView {
                LazyVGrid(columns: [
                    GridItem(.flexible()),
                    GridItem(.flexible()),
                    GridItem(.flexible())
                ], spacing: 20) {
                    
                    VStack{
                        Image()
                        Text("Sort")
                    }.onTapGesture{
                        
                    }
                    
                    ForEach(viewModel.favs, id: \.self) { fav in
                        VStack{
                            if(fav.character != nil){
                                Image(uiImage: convertBase64StringToImage(imageBase64String: viewModel.urlsToImages[fav.character!.iconUrl] ?? nil))
                                Text(fav.character!.name)
                            } else{
                                Image(uiImage: convertBase64StringToImage(imageBase64String: viewModel.urlsToImages[fav.game.iconUrl] ?? nil))
                                Text(fav.game.name)
                            }
                        }.onTapGesture {
                            favClosure(fav)
                        }
                    }
                    ForEach(getGamesToShow(games: viewModel.games, favs: viewModel.favs), id: \.self) { game in
                        VStack{
                            Image(uiImage: convertBase64StringToImage(imageBase64String: viewModel.urlsToImages[game.iconUrl] ?? nil))
                            Text(game.name)
                        }.onTapGesture {
                            gameClosure(game)
                        }
                    }
                    VStack{
                        Image()
                        Text("Acknowledgements")
                    }
                    VStack{
                        Image()
                        Text("About")
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
        @Published var favs: [ModelFavorite] = []
        @Published var urlsToImages: [String:String] = [:]
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func displayFavs(favorites: [ModelFavorite]) {
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



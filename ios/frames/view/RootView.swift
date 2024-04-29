//
//  ContentView.swift
//  ios
//
//  Created by Mitchell Drew on 10/8/23.
//

import SwiftUI
import presenter



struct RootView: View {
    let interactor: RootInteractor
    let homeView: HomeView
    let gameView: GameView
    let charView: CharView
    let searchView: SearchView
    let acknowledgmentView: AcknowledgmentView
    let aboutView: AboutView
    @StateObject var router: Router<Route> = Router(initial: .Home)
    @StateObject var viewModel = RootViewModel()
    
    
    init(interactor: RootInteractor, homeView: HomeView, gameView: GameView, charView:CharView, searchView: SearchView, acknowledgmentView: AcknowledgmentView, aboutView: AboutView){
        self.homeView = homeView
        self.gameView = gameView
        self.charView = charView
        self.searchView = searchView
        self.interactor = interactor
        self.acknowledgmentView = acknowledgmentView
        self.aboutView = aboutView
    }
    
    var body: some View {
        VStack{
            BannerView()
                .frame(width: 320,
                       height: 50)
            RouterHost(router: router) { route in
                switch route {
                case .Home: homeView
                case .Game: gameView
                case .Char: charView
                case .Search: searchView
                case .About: aboutView
                case .Acknowledgment: acknowledgmentView
                }
            }
            .onAppear{ interactor.viewResumed() }
            .onDisappear{ interactor.viewPaused() }
            .environmentObject(router)
            BannerView()
                .frame(width: 320,
                       height: 50)
        }
    }
    
    class RootViewModel: RootKView, ObservableObject {
        @Published var lastException: KotlinException? = nil
        
        func promptUpdate() {
        }
        
        func error(e: KotlinException) {
            lastException = e
        }
    }
}

//
//  ContentView.swift
//  ios
//
//  Created by Mitchell Drew on 10/8/23.
//

import SwiftUI
import presenter


enum RootRoute: Equatable {
    case Home
}

struct RootView: View {
    let interactor: RootInteractor
    let homeView: HomeView
    @StateObject var router: Router<RootRoute> = Router(initial: .Home)
    @StateObject var viewModel = RootViewModel()
    
    
    init(interactor: RootInteractor, homeView: HomeView){
        self.homeView = homeView
        self.interactor = interactor
        interactor.setView(view: viewModel)
    }
    
    var body: some View {
        RouterHost(router: router) { route in
            switch route {
            case .Home: homeView
            }
        }.onAppear{ interactor.viewResumed() }
            .onDisappear{ interactor.viewPaused() }
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

//
//  CharView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct CharView: View {
    let adUnitId:String
    let interactor:CharacterInteractor
    @StateObject var viewModel = CharViewModel()
    
    init(interactor:CharacterInteractor, adUnitId:String){
        self.interactor = interactor
        self.adUnitId = adUnitId
    }
    
    var body: some View {
        VStack{
            
        }.onAppear{
            interactor.setView(view: viewModel)
            interactor.viewResumed() }
        .onDisappear{ interactor.viewPaused() }
    }
    
    class CharViewModel: ObservableObject, CharacterKView {
        @Published var urlsToImages:[String:String] = [:]
        @Published var moves:[ModelMove] = []
        @Published var character: ModelCharacter? = nil
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        func display(url: String, imgBase64: String) async throws {
            urlsToImages[url] = imgBase64
        }
        
        func display(moves: [ModelMove]) {
            self.moves = moves
        }
        
        func display(character: ModelCharacter) {
            self.character = character
        }
        
        func displayMovesError(error: ModelError) {
            lastError = error
        }
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func displayCharError(error: ModelError) {
            lastError = error
        }
    }
}

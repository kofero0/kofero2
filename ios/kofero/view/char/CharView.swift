//
//  CharView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter

struct CharView: View {
    let charId:Int32
    let adUnitId:String
    let interactor:CharacterInteractor
    @StateObject var viewModel = CharViewModel()
    
    init(charId:Int32, interactor:CharacterInteractor, adUnitId:String){
        self.charId = charId
        self.interactor = interactor
        self.adUnitId = adUnitId
        interactor.setView(view: viewModel)
    }
    
    var body: some View {
        Text(/*@START_MENU_TOKEN@*/"Hello, World!"/*@END_MENU_TOKEN@*/)
    }
    
    class CharViewModel: ObservableObject, CharacterKView {
        @Published var urlsToImages:[String:String] = [:]
        @Published var moves:[ModelMove] = []
        @Published var character: ModelCharacter? = nil
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        func display(url: String, imgBase64: String) {
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
    }
}

struct CharView_Previews: PreviewProvider {
    static var previews: some View {
        CharView(charId: 0, interactor: MockCharInteractor(), adUnitId: "mock")
    }
}

class MockCharInteractor: CharacterInteractor {
    func setCharUid(uid: Int32) {}
    func setView(view: KView) {}
    func shutdown() {}
    func viewPaused() {}
    func viewResumed() {}
}

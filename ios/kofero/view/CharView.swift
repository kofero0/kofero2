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
            List(viewModel.displayMoves, children: \.attributes){ row in
                Text(row.name)
            }
        }.onAppear{
            interactor.setView(view: viewModel)
            interactor.viewResumed() }
        .onDisappear{ interactor.viewPaused() }
        .navigationTitle(viewModel.character?.name ?? "")
    }
    
    
    
    struct SectionHeader: View {
        @State var title: String
        @Binding var isOn: Bool
        @State var onLabel: String
        @State var offLabel: String
        
        var body: some View {
            Button(action: {
                withAnimation {
                    isOn.toggle()
                }
            }, label: {
                if isOn {
                    Text(onLabel)
                } else {
                    Text(offLabel)
                }
            })
            .font(Font.caption)
            .foregroundColor(.accentColor)
            .frame(maxWidth: .infinity, alignment: .trailing)
            .overlay(
                Text(title),
                alignment: .leading
            )
        }
    }
    
    
    struct CharSection: View {
        @State private var showingSection = false
        var move: ModelMove
        
        var body: some View{
            Section(
                header: SectionHeader(
                    title: move.name,
                    isOn: $showingSection,
                    onLabel: "Hide",
                    offLabel: "Show"
                )
            ){
                if showingSection {
                    ForEach(move.attributes.keys.sorted(), id: \.self){ attributeKey in
                        Text("\(attributeKey): \(move.attributes[attributeKey] ?? "")")
                    }
                }
            }
        }
    }
    
    struct DisplayMove: Identifiable {
        var id = UUID()
        var name: String
        var attributes: [DisplayMove]? = nil
    }
    
    class CharViewModel: ObservableObject, CharacterKView {
        @Published var urlsToImages:[String:String] = [:]
        @Published var moves:[ModelMove] = []
        @Published var displayMoves:[DisplayMove] = []
        @Published var character: ModelCharacter? = nil
        @Published var lastError: ModelError? = nil
        @Published var lastException: KotlinException? = nil
        
        func display(url: String, imgBase64: String) async throws {
            DispatchQueue.main.sync {
                urlsToImages[url] = imgBase64
            }
        }
        
        func display(moves: [ModelMove]) {
            DispatchQueue.main.sync {
                self.moves = moves
                displayMoves = []
                for move in moves {
                    var attributes = [DisplayMove]()
                    for attributeKey in move.attributes.keys {
                        attributes.append(DisplayMove(name: attributeKey + ": " + (move.attributes[attributeKey] ?? "")))
                    }
                    displayMoves.append(DisplayMove(name: move.name, attributes: attributes))
                }
            }
        }
        
        func display(character: ModelCharacter) {
            DispatchQueue.main.sync {
                self.character = character
            }
        }
        
        func displayMovesError(error: ModelError) {
            lastError = error
        }
        
        func error(e: KotlinException) {
            lastException = e
        }
        
        func displayCharError(error: ModelError) {
            DispatchQueue.main.sync {
                lastError = error
            }
        }
    }
}

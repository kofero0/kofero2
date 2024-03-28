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
    private let gameProvider: ProviderAbstract<ModelGame>
    private let favProvider: FavoritesProvider
    @StateObject var viewModel = CharViewModel()
    
    init(interactor:CharacterInteractor, favoritesProvider:FavoritesProvider, gameProvider: ProviderAbstract<ModelGame>, adUnitId:String){
        self.favProvider = favoritesProvider
        self.interactor = interactor
        self.gameProvider = gameProvider
        self.adUnitId = adUnitId
    }
    
    var body: some View {
        VStack{
            List(viewModel.displayMoves, children: \.attributes){ row in
                Text(row.name)
            }
        }.onAppear{
            interactor.setView(view: viewModel)
            viewModel.favsProvider = favProvider
            interactor.viewResumed() }
        .onDisappear{ interactor.viewPaused() }
        .navigationTitle(viewModel.character?.name ?? "")
        .toolbar{
            Button(action: {
                if let uChar = viewModel.character {
                    favClosure(uChar)
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
    
    private var favClosure: ((ModelCharacter) -> Void) {
        return { char in
            if let gUid = viewModel.gameUid {
                var ints = [KotlinInt]()
                ints.append(gUid.toKotlinInt())
                gameProvider.get(ids: ints, onEach: {either in
                    either.map{ gameArray in
                        if(viewModel.isFavorited){
                            viewModel.favsProvider?.delete(fav: ModelFavorite(game: gameArray![0] as! ModelGame, character: char)){_,_ in }
                        } else{
                            viewModel.favsProvider?.save(fav: ModelFavorite(game: gameArray![0] as! ModelGame, character: char)){_,_ in }
                        }
                        viewModel.isFavorited = !(viewModel.isFavorited)
                        return gameArray
                    }
                }) {_ in }
            }
        }
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
        @Published var isFavorited: Bool = false
        @Published var gameUid: Int32? = nil
        var favsProvider: FavoritesProvider? = nil
        
        @MainActor func display(url: String, imgBase64: String) async throws {
                urlsToImages[url] = imgBase64
        }
        
        private typealias Sorter = ((String, String) -> Bool)
        
        private var sf6Sorter: Sorter = {
            key1, key2 in
            func keyToInt(_ key:String) -> Int {
                switch key {
                case "Command": return 0
                case "Startup": return 1
                case "Active": return 2
                case "Recovery": return 3
                case "Duration": return 4
                case "On Hit": return 5
                case "On Punish Counter": return 6
                case "On Block": return 7
                case "Drive Rush On Hit": return 8
                case "Drive Rush On Block": return 9
                case "On Perfect Parry": return 10
                case "Damage": return 11
                case "Hitstun": return 12
                case "Blockstun": return 13
                case "Hitstop": return 14
                case "Attack Type": return 15
                case "Notes": return 999
                default: return 998
                }
            }
            return keyToInt(key1) < keyToInt(key2)
        }
        
        private var defaultSorter: Sorter = {
            key1, key2 in
            func keyToInt(_ key:String) -> Int {
                switch key{
                case "Startup": return 0
                case "Active": return 1
                case "Recovery": return 2
                case "Duration": return 3
                case "On Hit", "Hitstun": return 4
                case "On Block", "Blockstun": return 5
                case "Notes": return 999
                default: return 998
                }
            }
            return keyToInt(key1) < keyToInt(key2)
        }
        
        
        private func getSorter(gameUid:Int32) -> Sorter {
            switch gameUid{
            case 1892: return sf6Sorter
            default: return defaultSorter
            }
        }
        
        
        func display(moves: [ModelMove], gameUid: Int32) {
            DispatchQueue.main.sync {
                self.gameUid = gameUid
                self.moves = moves
                displayMoves = []
                for move in moves {
                    var attributes = [DisplayMove]()
                    for attributeKey in move.attributes.keys.sorted(by: getSorter(gameUid: gameUid)) {
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
            favsProvider?.get{ either,error in
                either?.map { favs in
                    if let uFavs = favs {
                        for fav in uFavs {
                            let cFav = fav as! ModelFavorite
                            if(cFav.character?.uid == character.uid){
                                self.isFavorited = true
                            }
                        }
                    }
                    return nil
                }
            }
        }
        
        func displayMovesError(error: ModelError) {
            DispatchQueue.main.sync {
                lastError = error
            }
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

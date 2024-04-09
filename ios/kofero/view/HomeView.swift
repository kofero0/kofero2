//
//  HomeView.swift
//  kofero
//
//  Created by Mitchell Drew on 16/8/23.
//

import SwiftUI
import presenter
import Combine
import GoogleMobileAds

private struct BannerView: UIViewControllerRepresentable {
  @State private var viewWidth: CGFloat = .zero
  private let bannerView = GADBannerView()
  private let adUnitID = "ca-app-pub-3940256099942544/2934735716"

  func makeUIViewController(context: Context) -> some UIViewController {
    let bannerViewController = BannerViewController()
    bannerView.adUnitID = adUnitID
      bannerView.adSize = kGADAdSizeBanner
    bannerView.rootViewController = bannerViewController
    bannerView.delegate = context.coordinator
    bannerView.translatesAutoresizingMaskIntoConstraints = false
    bannerViewController.view.addSubview(bannerView)
    // Constrain GADBannerView to the bottom of the view.
    NSLayoutConstraint.activate([
      bannerView.bottomAnchor.constraint(
        equalTo: bannerViewController.view.safeAreaLayoutGuide.topAnchor),
      bannerView.centerXAnchor.constraint(equalTo: bannerViewController.view.centerXAnchor),
    ])
    bannerViewController.delegate = context.coordinator

    return bannerViewController
  }

  func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
    guard viewWidth != .zero else { return }
    bannerView.adSize = GADCurrentOrientationAnchoredAdaptiveBannerAdSizeWithWidth(viewWidth)
    bannerView.load(GADRequest())
  }

  func makeCoordinator() -> Coordinator {
    Coordinator(self)
  }

  fileprivate class Coordinator: NSObject, BannerViewControllerWidthDelegate, GADBannerViewDelegate
  {
    let parent: BannerView

    init(_ parent: BannerView) {
      self.parent = parent
    }

    // MARK: - BannerViewControllerWidthDelegate methods

    func bannerViewController(
      _ bannerViewController: BannerViewController, didUpdate width: CGFloat
    ) {
      parent.viewWidth = width
    }

    
      func bannerViewDidReceiveAd(_ bannerView: GADBannerView) {
        print("@@@@@@@@\(#function) called")
      }

      func bannerView(_ bannerView: GADBannerView, didFailToReceiveAdWithError error: Error) {
        print("@@@@@@@\(#function) called")
      }

      func bannerViewDidRecordImpression(_ bannerView: GADBannerView) {
        print("@@@@@@@@\(#function) called")
      }

      func bannerViewWillPresentScreen(_ bannerView: GADBannerView) {
        print("@@@@@@@@\(#function) called")
      }

      func bannerViewWillDismissScreen(_ bannerView: GADBannerView) {
        print("@@@@@@@@\(#function) called")
      }

      func bannerViewDidDismissScreen(_ bannerView: GADBannerView) {
        print("@@@@@@@@@\(#function) called")
      }
  }
}

protocol BannerViewControllerWidthDelegate: AnyObject {
  func bannerViewController(_ bannerViewController: BannerViewController, didUpdate width: CGFloat)
}

class BannerViewController: UIViewController {

  weak var delegate: BannerViewControllerWidthDelegate?

  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)

    delegate?.bannerViewController(
      self, didUpdate: view.frame.inset(by: view.safeAreaInsets).size.width)
  }

  override func viewWillTransition(
    to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator
  ) {
    coordinator.animate { _ in
      // do nothing
    } completion: { _ in
      self.delegate?.bannerViewController(
        self, didUpdate: self.view.frame.inset(by: self.view.safeAreaInsets).size.width)
    }
  }
}


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
    
    @State private var showingSortAlert = false
    @State private var showingAcknowledgmentAlert = false
    @State private var showingAboutAlert = false
    
    var body: some View {
        VStack{
            BannerView()
        
        ScrollView {
                LazyVGrid(columns: [
                    GridItem(.flexible()),
                    GridItem(.flexible()),
                    GridItem(.flexible())
                ], spacing: 20) {
                    
                    VStack{
                        Image(systemName: "line.3.horizontal.decrease.circle")
                            .resizable()
                                .frame(width: 100, height: 100)
                        Text("Sort")
                    }.onTapGesture{showingSortAlert = true}
                    .alert("Coming soon!", isPresented: $showingSortAlert) {
                        Button("OK", role: .cancel) { }
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
                        Image(systemName: "figure.wave.circle")
                            .resizable()
                                .frame(width: 100, height: 100)
                        Text("Acknowledgments")
                    }.onTapGesture{showingAcknowledgmentAlert = true}
                        .alert(viewModel.acknowledgment, isPresented: $showingAcknowledgmentAlert) {
                            Button("OK", role: .cancel) { }
                        }
                    
                    VStack{
                        Image(systemName: "info.circle")
                            .resizable()
                                .frame(width: 100, height: 100)
                        Text("About")
                    }.onTapGesture{viewModel.showAboutAlert = true}
                    .alert(isPresented: $viewModel.showAboutAlert, content: { () -> Alert in
                        Alert(title: Text("About"), message: Text(viewModel.copy?.about ?? ""), dismissButton: .default(Text("Okay")))
                    })
                }
            }
            BannerView()
                .frame(width: 320,
                       height: 50)
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
        @Published var copy: ModelCopy? = nil
        @Published var acknowledgment: String = ""
        @Published var showAboutAlert = false
        
        
        func displayCopy(copy: ModelCopy) {
            DispatchQueue.main.sync {
                self.copy = copy
                acknowledgment = ""
                for str in copy.acknowledgment.components(separatedBy: "\\n") {
                    acknowledgment += str
                }
            }
        }
        
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
                urlsToImages[url] = imgBase64
        }
    }
}



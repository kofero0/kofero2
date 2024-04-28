//
//  iosApp.swift
//  ios
//
//  Created by Mitchell Drew on 10/8/23.
//

import SwiftUI
import NeedleFoundation
import GoogleMobileAds
import FirebaseCore
import presenter


class AppDelegate: UIResponder, UIApplicationDelegate {

  func application(_ application: UIApplication,
      didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    GADMobileAds.sharedInstance().start(completionHandler: nil)
    FirebaseApp.configure()

    return true
  }
}

@main
struct iosApp: App {
    private let rootComponent: RootComponent
    @UIApplicationDelegateAdaptor(AppDelegate.self) var delegate

    
    init() {
        registerProviderFactories()
        self.rootComponent = RootComponent()
        fatalError("DEPRECATED!!!!!!!!!!")
    }
    
    
    var body: some Scene {
        WindowGroup {
            rootComponent.rootView
        }
    }
}

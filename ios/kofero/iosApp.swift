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


class AppDelegate: NSObject, UIApplicationDelegate {
  func application(_ application: UIApplication,
                   didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
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
        GADMobileAds.sharedInstance().start(completionHandler: nil)
        self.rootComponent = RootComponent()
    }
    
    
    var body: some Scene {
        WindowGroup {
            rootComponent.rootView
        }
    }
}

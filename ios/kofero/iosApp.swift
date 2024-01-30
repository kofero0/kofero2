//
//  iosApp.swift
//  ios
//
//  Created by Mitchell Drew on 10/8/23.
//

import SwiftUI
import NeedleFoundation
import GoogleMobileAds
import presenter

@main
struct iosApp: App {
    private let rootComponent: RootComponent
    
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

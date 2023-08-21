//
//  iosApp.swift
//  ios
//
//  Created by Mitchell Drew on 10/8/23.
//

import SwiftUI
import NeedleFoundation
import GoogleMobileAds

@main
struct iosApp: App {
    
    init() {
        registerProviderFactories()
        GADMobileAds.sharedInstance().start(completionHandler: nil)
    }
    
    
    var body: some Scene {
        WindowGroup {
            AnyView(_fromValue: UINavigationController())
        }
    }
}

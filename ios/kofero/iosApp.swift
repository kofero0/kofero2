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
        print("@@@")
        rootComponent.statusProvider.getBackendStatus{either,error in
            print("EITHER RETURNED")
//            print(error)
//            print(either?.isRight())
//            print(either?.isLeft())
            either!.mapLeft{ statusError in print(statusError) }
            either!.map{status in
                print("status version: \(status?.version), time: \(status?.time)")
            }
        }
    }
    
    
    var body: some Scene {
        WindowGroup {
            //rootComponent.navController
           // AnyView(_fromValue: UINavigationController())
        }
    }
}

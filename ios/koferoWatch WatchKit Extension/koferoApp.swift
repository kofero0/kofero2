//
//  koferoApp.swift
//  koferoWatch WatchKit Extension
//
//  Created by Mitchell Drew on 6/2/24.
//

import SwiftUI

@main
struct koferoApp: App {
    @SceneBuilder var body: some Scene {
        WindowGroup {
            NavigationView {
                ContentView()
            }
        }

        WKNotificationScene(controller: NotificationController.self, category: "myCategory")
    }
}

//
//  RouterHost.swift
//  kofero
//
//  Created by Mitchell Drew on 28/1/24.
//

import Foundation
import SwiftUI
import UIKit

struct RouterHost<Route: Equatable, Screen: View>: UIViewControllerRepresentable {
    let router: Router<Route>
    
    @ViewBuilder
    let builder: (Route) -> Screen
    
    func makeUIViewController(context: Context) -> UINavigationController {
        let navigation = UINavigationController()
        for route in router.routes {
            navigation.pushViewController(
                UIHostingController(rootView: builder(route)), animated: false
            )
        }
        router.onPush = { route in
            navigation.pushViewController(
                UIHostingController(rootView: builder(route)), animated: true
            )
        }
        router.onPop = {
            navigation.popViewController(animated: true)
        }
        return navigation
    }
    
    func updateUIViewController(_ uiViewController: UINavigationController, context: Context) {
    }
    
    typealias UIViewControllerType = UINavigationController
}

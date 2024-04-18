//
//  IdentityProviderImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 1/2/24.
//

import presenter
import UIKit

class IdentityProviderImpl: IdentityProvider {
    func getDeviceId() -> String {
        return UIDevice.current.identifierForVendor!.uuidString
    }
}

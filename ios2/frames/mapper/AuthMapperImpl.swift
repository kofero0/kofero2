//
//  AuthMapperImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 1/2/24.
//

import Foundation
import presenter
import SwiftyJSON


class AuthMapperImpl: AuthMapper {
    func getAuthToken(jsonString: String) -> String {
        return JSON(parseJSON: jsonString)["token"].stringValue
    }
}

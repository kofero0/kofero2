//
//  RequestMapper.swift
//  kofero
//
//  Created by Mitchell Drew on 22/1/24.
//

import Foundation
import SwiftyJSON
import presenter

class RequestMapperImpl: RequestMapper {
    public override func mapRight(data: [KotlinInt]) -> String {
        var ret = "["
        for int in data {
            ret = ret + "\(int),"
        }
        ret = ret + "]"
        return ret
    }
    
    public override func mapLeft(data: String) -> [KotlinInt] {
        fatalError("how did we get here? \(data)")
    }
}

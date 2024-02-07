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
        if(data.count == 0){ return "[]" }
        var ret = "["
        for int in data {
            ret += "\(int),"
        }
        ret.removeLast()
        ret += "]"
        print(ret)
        return ret
    }
    
    public override func mapLeft(data: String) -> [KotlinInt] {
        fatalError("how did we get here? \(data)")
    }
}

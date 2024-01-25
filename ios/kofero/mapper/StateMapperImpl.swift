//
//  StateMapperImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 24/1/24.
//

import Foundation
import SwiftyJSON
import presenter

//TODO: LOW PRIORITY, NOOP FOR NOW
class StateMapperImpl: StringMapper<[KotlinLong:ModelEvent]> {
    public override func map(data: [KotlinLong : ModelEvent]) throws -> String {
        var cData = [Int64:Any?]()
        for key in data.keys {
            cData[key.int64Value] = data[key]
        }
        return JSON(cData).rawString()!
    }
    
    public override func map(data: String) throws -> [KotlinLong : ModelEvent] {
        var jsonDict = JSON(stringLiteral: data).dictionaryValue
        var ret = [KotlinLong:ModelEvent]()
        return ret
    }
}

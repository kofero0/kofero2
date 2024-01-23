//
//  MoveSerializer.swift
//  provider
//
//  Created by Mitchell Drew on 12/3/21.
//

import Foundation
import presenter
import SwiftyJSON

public class MoveMapperImpl: MoveMapper{
    private let encoder:StringEncoder<[JSON]>
    
    public init(encoder:StringEncoder<[JSON]>) {
        self.encoder = encoder
    }
    
    public override func mapLeft(data: String) -> [ModelMove] {
            let json = try JSON(stringLiteral: data)
            var ret = [ModelMove]()
            for element in json.arrayValue {
                ret.append(serialize(json: element))
            }
            return ret
    }
    
    public override func mapRight(data: [ModelMove]) -> String {
            var json = [JSON]()
            for move in data {
                var moveJson = JSON()
                moveJson["uid"].int32 = move.uid
                moveJson["name"].string = move.name
                moveJson["attributes"].dictionaryObject = move.attributes
                json.append(moveJson)
            }
        do{
            return try encoder.encode(json)
        }catch{
            fatalError("how did we get here? \(error)")
        }
    }
    
    private func serialize(json: JSON) -> ModelMove {
        return ModelMove(uid: json["uid"].int32Value, name: json["name"].stringValue, attributes: transformDict(dict: json["attributes"].dictionaryValue))
    }
    
    private func transformDict(dict:[String:JSON]) -> [String:String] {
        var mDict = dict
        var ret = [String:String]()
        for key in dict.keys {
            if let value = mDict.removeValue(forKey: key) {
                ret.updateValue(value.stringValue, forKey: key)
            }
        }
        return ret
    }
}

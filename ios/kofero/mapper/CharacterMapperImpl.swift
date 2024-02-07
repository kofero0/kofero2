//
//  CharacterSerializer.swift
//  provider
//
//  Created by Mitchell Drew on 10/3/21.
//

import Foundation
import presenter
import SwiftyJSON

public class CharacterMapperImpl: CharMapper {
    
    private let encoder:StringEncoder<[JSON]>
    
    public init(encoder:StringEncoder<[JSON]>){
        self.encoder = encoder
    }
    
    public override func mapLeft(data: String) -> [ModelCharacter] {
        let json = JSON(parseJSON: data)
            var ret = [ModelCharacter]()
            for element in json.arrayValue {
                ret.append(serialize(json: element))
            }
            return ret
    }
    
    public override func mapRight(data: [ModelCharacter]) -> String {
            var json = [JSON]()
            for char in data {
                var charJson = JSON()
                charJson["uid"].int32 = char.uid
                charJson["name"].string = char.name
                charJson["moveIds"].arrayObject = char.moveIds
                charJson["attributes"].dictionaryObject = char.attributes
                charJson["iconUrl"].string = char.iconUrl
                json.append(charJson)
            }
        do{
            return try encoder.encode(json)
        }
        catch{
            fatalError("how did we get here? \(error)")
        }
    }
    
    private func serialize(json: JSON) -> ModelCharacter {
        var moveIds = [KotlinInt]()
        
        for element in json["moveIds"].arrayValue {
            moveIds.append(KotlinInt(int: element.int32Value))
        }
        return ModelCharacter(uid: json["uid"].int32Value, name: json["name"].stringValue, attributes: transformDict(dict: json["attributes"].dictionaryValue), moveIds: moveIds, iconUrl: json["iconUrl"].stringValue)
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

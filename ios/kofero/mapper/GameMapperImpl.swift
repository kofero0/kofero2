//
//  GameSerializer.swift
//  provider
//
//  Created by Mitchell Drew on 27/2/21.
//

import Foundation
import presenter
import SwiftyJSON

public class GameMapperImpl: GameMapper {
    private let encoder:StringEncoder<[JSON]>
    
    public init(encoder:StringEncoder<[JSON]>) {
        self.encoder = encoder
        super.init()
    }
    
    public override func mapLeft(data: String) -> [ModelGame] {
        let json = JSON(stringLiteral: data)
        var ret = [ModelGame]()
        for element in json.arrayValue {
            ret.append(serialize(json: element))
        }
        return ret
    }
    
    public override func mapRight(data: [ModelGame]) -> String {
        var json = [JSON]()
        for game in data {
            var gameJson = JSON()
            gameJson["uid"].int32 = game.uid
            gameJson["name"].string = game.name
            gameJson["charIds"].arrayObject = game.charIds
            gameJson["iconUrl"].string = game.iconUrl
            json.append(gameJson)
        }
        do{
            return try encoder.encode(json)
        }
        catch{
            fatalError("how did we get here? \(error)")
        }
    }
    
    private func serialize(json:JSON) -> ModelGame{
        var characterIds = [KotlinInt]()
        for charIdElement in json["charIds"].arrayValue {
            characterIds.append(KotlinInt(int: charIdElement.int32Value))
        }
        return ModelGame(uid: json["uid"].int32Value, name: json["name"].stringValue, charIds: characterIds, iconUrl: json["iconUrl"].stringValue)
    }
}

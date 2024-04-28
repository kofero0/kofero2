//
//  FavoritesMapperImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 15/2/24.
//

import Foundation
import presenter
import SwiftyJSON

class FavoritesMapper: StringMapper<[ModelFavorite]> {
    private let encoder:StringEncoder<[JSON]>
    private let gameMapper:GameMapperImpl
    private let charMapper:CharacterMapperImpl
    
    public init(encoder: StringEncoder<[JSON]>, gameMapper:GameMapperImpl, charMapper: CharacterMapperImpl) {
        self.encoder = encoder
        self.gameMapper = gameMapper
        self.charMapper = charMapper
        super.init()
    }
    
    
    public override func map(data: String) throws -> [ModelFavorite] {
        let json = JSON(parseJSON: data)
        var ret = [ModelFavorite]()
        for element in json.arrayValue {
            var char: ModelCharacter? = nil
            if(element["character"].exists()){
                char = charMapper.serialize(json: element["character"])
            }
            ret.append(ModelFavorite(game: gameMapper.serialize(json: element["game"]), character: char))
        }
        return ret
    }
    
    public override func map(data: [ModelFavorite]) throws -> String {
                var json = [JSON]()
                for fav in data {
                    var favJson = JSON()
                    if(fav.character != nil){
                        var charJson = JSON()
                        charJson["uid"].int32 = fav.character!.uid
                        charJson["name"].string = fav.character!.name
                        charJson["moveIds"].arrayObject = fav.character!.moveIds
                        charJson["attributes"].dictionaryObject = fav.character!.attributes
                        charJson["iconUrl"].string = fav.character!.iconUrl
                        favJson["character"] = charJson
                    }
                    var gameJson = JSON()
                    gameJson["uid"].int32 = fav.game.uid
                    gameJson["name"].string = fav.game.name
                    gameJson["charIds"].arrayObject = fav.game.charIds
                    gameJson["iconUrl"].string = fav.game.iconUrl
                    favJson["game"] = gameJson
                    json.append(favJson)
                }
            do{
                return try encoder.encode(json)
            }
            catch{
                fatalError("how did we get here? \(error)")
            }
    }
}

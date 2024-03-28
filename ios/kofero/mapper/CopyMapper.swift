//
//  CopyMapper.swift
//  kofero
//
//  Created by Mitchell Drew on 26/3/24.
//

import Foundation
import SwiftyJSON
import presenter

class CopyMapperImpl: CopyMapper {
    
    public override func mapLeft(data: String) -> ModelCopy {
        print("%%%mapping")
        print(data)
        let json = JSON(parseJSON: data)
        return ModelCopy(about: json["about"].stringValue, acknowledgment: json["acknowledgment"].stringValue, privacyPolicyUrl: json["privacyPolicyUrl"].stringValue)
    }
    
    public override func mapRight(data: ModelCopy) -> String {
        var json = JSON()
        json["about"].string = data.about
        json["acknowledgment"].string = data.acknowledgment
        json["privacyPolicyUrl"].string = data.privacyPolicyUrl
        if let ret = json.rawString(){
            return ret
        }
        return ""
    }

}

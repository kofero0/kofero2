//
//  StatusMapper.swift
//  kofero
//
//  Created by Mitchell Drew on 18/1/24.
//

import Foundation
import presenter
import SwiftyJSON

public class StatusMapperImpl:StatusMapper{
    public override func mapLeft(data: String) -> ModelStatus {
        let json = JSON(parseJSON: data)
        return ModelStatus(time: json["time"].int64Value, version: json["version"].stringValue)
    }
    
    public override func mapRight(data: ModelStatus) -> String {
        fatalError("how did this happen?")
    }
}

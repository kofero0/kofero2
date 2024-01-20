//
//  StatusMapper.swift
//  kofero
//
//  Created by Mitchell Drew on 18/1/24.
//

import Foundation
import presenter
import SwiftyJSON

public class StatusMapper:DataMapper<ModelStatus>{
    private let encoder:DataEncoder<[JSON]>
    
    public init(encoder:DataEncoder<[JSON]>){
        self.encoder = encoder
    }
    
    public override func map(data: Data) throws -> ModelStatus {
        let json = try JSON(data: data)
        return ModelStatus(time: json["time"].int64Value, version: json["version"].stringValue)
    }

}

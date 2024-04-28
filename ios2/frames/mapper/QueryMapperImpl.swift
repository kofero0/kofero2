//
//  QueryMapperImpl.swift
//  FRAMES
//
//  Created by Mitch Drew on 24.04.2024.
//

import Foundation
import presenter

class QueryMapperImpl: QueryMapper {
    public override func mapLeft(data: String) -> [String] {
        return data.split(separator: " ") as? [String] ?? []
    }
    
    public override func mapRight(data: [String]) -> String {
        fatalError("how did we get here?")
    }
}

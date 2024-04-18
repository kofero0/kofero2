//
//  JsonDataEncoder.swift
//  provider
//
//  Created by Mitchell Drew on 5/4/21.
//

import Foundation


open class JsonStringEncoder<I:Encodable>: StringEncoder<I> {
    private let encoder = JSONEncoder()
    
    public override init(){}
    
    public override func encode(_ value: I) throws -> String {
        return try String(data: encoder.encode(value), encoding: .utf8) ?? ""
    }
}

//
//  JsonEncoder.swift
//  provider
//
//  Created by Mitchell Drew on 1/4/21.
//

import Foundation


open class StringEncoder<I:Encodable>: Encoder {
    public typealias O = String
    
    public func encode(_ value: I) throws -> String {
        fatalError("override me!")
    }
}

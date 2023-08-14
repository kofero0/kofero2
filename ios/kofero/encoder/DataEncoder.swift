//
//  JsonEncoder.swift
//  provider
//
//  Created by Mitchell Drew on 1/4/21.
//

import Foundation


open class DataEncoder<I:Encodable>: Encoder {
    public typealias O = Data
    
    public func encode(_ value: I) throws -> Data {
        fatalError("override me!")
    }
}

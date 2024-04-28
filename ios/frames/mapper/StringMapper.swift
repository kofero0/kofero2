//
//  StringMapper.swift
//  kofero
//
//  Created by Mitchell Drew on 24/1/24.
//

import Foundation

open class StringMapper<O>: Mapper {
    typealias I = String
    
    public func map(data: String) throws -> O { fatalError("Override me!") }
    
    public func map(data: O) throws -> String { fatalError("Override me!") }
}

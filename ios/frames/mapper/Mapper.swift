//
//  Mapper.swift
//  provider
//
//  Created by Mitchell Drew on 26/2/21.
//

import Foundation

protocol Mapper {
    associatedtype I
    associatedtype O
    func map(data:I) throws -> O
    func map(data:O) throws -> I
}

//
//  StateProviderImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 21/8/23.
//

import Foundation
import presenter

class StateProviderImpl: StateProvider {
    let arrowExtensions = ArrowExtensions()
    
    func get() async throws -> Arrow_coreEither<ModelProviderError, NSDictionary> {
        return arrowExtensions.buildNSDictionaryEitherRight(dict: [:])
    }
    
    func save(map: [KotlinLong : ModelEvent]) async throws -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
        return arrowExtensions.buildUnitEitherRight()
    }
}

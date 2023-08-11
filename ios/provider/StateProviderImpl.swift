//
//  StateLogger.swift
//  provider
//
//  Created by Mitchell Drew on 3/8/23.
//

import Foundation
import presenter

public class StateProviderImpl: StateProvider {
    
    public func get() -> Arrow_coreEither<ModelProviderError, NSDictionary> {
    }
    
    public func save(map: [KotlinLong : ModelEvent]) -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
        <#code#>
    }
    
    
}

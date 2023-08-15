//
//  FavoritesProvider.swift
//  provider
//
//  Created by Mitchell Drew on 19/4/21.
//

import Foundation
import presenter

public class FavoritesProviderImpl: FavoritesProvider {
    private let arrowExtensions = ArrowExtensions()
    private let defaults:IUserDefaults
    private let FAVS_KEY = "favs"
    
    public init(defaults:IUserDefaults){
        self.defaults = defaults
    }
    
    public func delete(item: ModelObj) -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
            let favs = defaults.object(forKey: FAVS_KEY)
            if var uFavs = favs as? [ModelObj] {
                uFavs.removeAll{obj in return obj.uid == item.uid}
                defaults.set(uFavs, forKey: FAVS_KEY)
                return arrowExtensions.buildUnitEitherRight()
            }
        return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
    public func save(item: ModelObj) -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
            let favs = defaults.object(forKey: FAVS_KEY)
            if var uFavs = favs as? [ModelObj] {
                uFavs.append(item)
                defaults.set(uFavs, forKey: FAVS_KEY)
                return arrowExtensions.buildUnitEitherRight()
            }
        return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
    public func get(ids: [KotlinInt]) -> Arrow_coreIor<ModelProviderError, NSArray> {
        if let favs = defaults.object(forKey: FAVS_KEY) as? [ModelObj]{
            return arrowExtensions.buildListIorRight(right: favs)
        }
        return arrowExtensions.buildListIorLeft(left: ModelIncorrectCount(ids: []))
    }
}

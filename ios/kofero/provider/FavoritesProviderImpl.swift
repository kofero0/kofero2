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
    
    public func delete(id: Int32) async throws -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
                    let favs = defaults.object(forKey: FAVS_KEY)
                    if var uFavs = favs as? [ModelFavorite] {
                        uFavs.removeAll{obj in return obj.uid == id}
                        defaults.set(uFavs, forKey: FAVS_KEY)
                        return arrowExtensions.buildUnitEitherRight()
                    }
                return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
    public func save(fav: ModelFavorite) async throws -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
                    let favs = defaults.object(forKey: FAVS_KEY)
                    if var uFavs = favs as? [ModelFavorite] {
                        uFavs.append(fav)
                        defaults.set(uFavs, forKey: FAVS_KEY)
                        return arrowExtensions.buildUnitEitherRight()
                    }
                return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
    }
    
    public func get() async throws -> Arrow_coreEither<ModelProviderError, NSArray> {
        if let favs = defaults.object(forKey: FAVS_KEY) as? [ModelFavorite]{
            return arrowExtensions.buildListEitherRight(right: favs)
        }
        return arrowExtensions.buildListEitherRight(right: [])
    }
}

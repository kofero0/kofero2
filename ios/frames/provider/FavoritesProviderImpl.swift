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
    private let loggingProvider: LoggingProvider
    private let diskAccessor: DiskAccessor
    private let mapper: FavoritesMapper
    private let fileName = "favs"
    
    init(loggingProvider: LoggingProvider, diskAccessor: DiskAccessor, mapper: FavoritesMapper){
        self.loggingProvider = loggingProvider
        self.diskAccessor = diskAccessor
        self.mapper = mapper
    }
    
    public func delete(fav: ModelFavorite) async throws -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
        do{
            var favs = try mapper.map(data: diskAccessor.read(fileName: fileName))
            favs.removeAll{savedFav in return fav.character?.uid == savedFav.character?.uid && fav.game.uid == savedFav.game.uid}
            diskAccessor.write(fileName: fileName, json: try mapper.map(data: favs))
            return arrowExtensions.buildUnitEitherRight()
        } catch {
            return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
        }
    }
    
    public func save(fav: ModelFavorite) async throws -> Arrow_coreEither<ModelProviderError, KotlinUnit> {
        do{
            var favs = try mapper.map(data: diskAccessor.read(fileName: fileName))
            favs.append(fav)
            diskAccessor.write(fileName: fileName, json: try mapper.map(data: favs))
            return arrowExtensions.buildUnitEitherRight()
        } catch {
            return arrowExtensions.buildUnitEitherLeft(left: ModelIncorrectCount(ids: []))
        }
    }
    
    public func get() async throws -> Arrow_coreEither<ModelProviderError, NSArray> {
        do{
            return try arrowExtensions.buildListEitherRight(right: mapper.map(data: diskAccessor.read(fileName: fileName)))
        } catch {
            return arrowExtensions.buildListEitherRight(right: [])
        }
        
    }
}

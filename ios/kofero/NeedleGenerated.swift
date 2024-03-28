

import Foundation
import NeedleFoundation
import SwiftUI
import SwiftyJSON
import presenter

// swiftlint:disable unused_declaration
private let needleDependenciesHash : String? = nil

// MARK: - Registration

public func registerProviderFactories() {
    __DependencyProviderRegistry.instance.registerDependencyProviderFactory(for: "^->RootComponent->GameComponent") { component in
        return GameDependency6174651c56123eef7457Provider(component: component)
    }
    __DependencyProviderRegistry.instance.registerDependencyProviderFactory(for: "^->RootComponent") { component in
        return EmptyDependencyProvider(component: component)
    }
    __DependencyProviderRegistry.instance.registerDependencyProviderFactory(for: "^->RootComponent->MoveComponent") { component in
        return MoveDependency60ec017cefc7ff9083ceProvider(component: component)
    }
    __DependencyProviderRegistry.instance.registerDependencyProviderFactory(for: "^->RootComponent->CharacterComponent") { component in
        return CharacterDependency42b99561bd73739b9ec3Provider(component: component)
    }
    __DependencyProviderRegistry.instance.registerDependencyProviderFactory(for: "^->RootComponent->HomeComponent") { component in
        return HomeDependencycad225e9266b3c9a56ddProvider(component: component)
    }
    
}

// MARK: - Providers

private class GameDependency6174651c56123eef7457BaseProvider: GameDependency {
    var imageProvider: ImageProvider {
        return rootComponent.imageProvider
    }
    var charProvider: ProviderAbstract<ModelCharacter> {
        return rootComponent.charProvider
    }
    var jsonEncoder: StringEncoder<[JSON]> {
        return rootComponent.jsonEncoder
    }
    var bannerAdUnitId: String {
        return rootComponent.bannerAdUnitId
    }
    var loggingProvider: LoggingProvider {
        return rootComponent.loggingProvider
    }
    var stateLogger: StateLogger {
        return rootComponent.stateLogger
    }
    var stateReducer: StateReducer {
        return rootComponent.stateReducer
    }
    var dispatcherProvider: DispatcherProvider {
        return rootComponent.dispatcherProvider
    }
    var authProvider: AuthProvider {
        return rootComponent.authProvider
    }
    var urlPrefix: String {
        return rootComponent.urlPrefix
    }
    var requestMapper: RequestMapper {
        return rootComponent.requestMapper
    }
    var diskAccessor: DiskAccessor {
        return rootComponent.diskAccessor
    }
    var charInteractor: CharacterInteractor {
        return rootComponent.charInteractor
    }
    var authHttpClient: Ktor_client_coreHttpClient {
        return rootComponent.authHttpClient
    }
    private let rootComponent: RootComponent
    init(rootComponent: RootComponent) {
        self.rootComponent = rootComponent
    }
}
/// ^->RootComponent->GameComponent
private class GameDependency6174651c56123eef7457Provider: GameDependency6174651c56123eef7457BaseProvider {
    init(component: NeedleFoundation.Scope) {
        super.init(rootComponent: component.parent as! RootComponent)
    }
}
private class MoveDependency60ec017cefc7ff9083ceBaseProvider: MoveDependency {
    var jsonEncoder: StringEncoder<[JSON]> {
        return rootComponent.jsonEncoder
    }
    var loggingProvider: LoggingProvider {
        return rootComponent.loggingProvider
    }
    var authProvider: AuthProvider {
        return rootComponent.authProvider
    }
    var urlPrefix: String {
        return rootComponent.urlPrefix
    }
    var requestMapper: RequestMapper {
        return rootComponent.requestMapper
    }
    var diskAccessor: DiskAccessor {
        return rootComponent.diskAccessor
    }
    var authHttpClient: Ktor_client_coreHttpClient {
        return rootComponent.authHttpClient
    }
    private let rootComponent: RootComponent
    init(rootComponent: RootComponent) {
        self.rootComponent = rootComponent
    }
}
/// ^->RootComponent->MoveComponent
private class MoveDependency60ec017cefc7ff9083ceProvider: MoveDependency60ec017cefc7ff9083ceBaseProvider {
    init(component: NeedleFoundation.Scope) {
        super.init(rootComponent: component.parent as! RootComponent)
    }
}
private class CharacterDependency42b99561bd73739b9ec3BaseProvider: CharacterDependency {
    var moveProvider: ProviderAbstract<ModelMove> {
        return rootComponent.moveProvider
    }
    var imageProvider: ImageProvider {
        return rootComponent.imageProvider
    }
    var jsonEncoder: StringEncoder<[JSON]> {
        return rootComponent.jsonEncoder
    }
    var bannerAdUnitId: String {
        return rootComponent.bannerAdUnitId
    }
    var loggingProvider: LoggingProvider {
        return rootComponent.loggingProvider
    }
    var stateLogger: StateLogger {
        return rootComponent.stateLogger
    }
    var stateReducer: StateReducer {
        return rootComponent.stateReducer
    }
    var dispatcherProvider: DispatcherProvider {
        return rootComponent.dispatcherProvider
    }
    var authProvider: AuthProvider {
        return rootComponent.authProvider
    }
    var urlPrefix: String {
        return rootComponent.urlPrefix
    }
    var requestMapper: RequestMapper {
        return rootComponent.requestMapper
    }
    var diskAccessor: DiskAccessor {
        return rootComponent.diskAccessor
    }
    var authHttpClient: Ktor_client_coreHttpClient {
        return rootComponent.authHttpClient
    }
    private let rootComponent: RootComponent
    init(rootComponent: RootComponent) {
        self.rootComponent = rootComponent
    }
}
/// ^->RootComponent->CharacterComponent
private class CharacterDependency42b99561bd73739b9ec3Provider: CharacterDependency42b99561bd73739b9ec3BaseProvider {
    init(component: NeedleFoundation.Scope) {
        super.init(rootComponent: component.parent as! RootComponent)
    }
}
private class HomeDependencycad225e9266b3c9a56ddBaseProvider: HomeDependency {
    var bannerAdUnitId: String {
        return rootComponent.bannerAdUnitId
    }
    var gameProvider: ProviderAbstract<ModelGame> {
        return rootComponent.gameProvider
    }
    var charProvider: ProviderAbstract<ModelCharacter> {
        return rootComponent.charProvider
    }
    var imageProvider: ImageProvider {
        return rootComponent.imageProvider
    }
    var favoritesProvider: FavoritesProvider {
        return rootComponent.favoritesProvider
    }
    var stateLogger: StateLogger {
        return rootComponent.stateLogger
    }
    var stateReducer: StateReducer {
        return rootComponent.stateReducer
    }
    var loggingProvider: LoggingProvider {
        return rootComponent.loggingProvider
    }
    var dispatcherProvider: DispatcherProvider {
        return rootComponent.dispatcherProvider
    }
    var gameInteractor: GameInteractor {
        return rootComponent.gameInteractor
    }
    var charInteractor: CharacterInteractor {
        return rootComponent.charInteractor
    }
    var copyProvider: CopyProvider {
        return rootComponent.copyProvider
    }
    private let rootComponent: RootComponent
    init(rootComponent: RootComponent) {
        self.rootComponent = rootComponent
    }
}
/// ^->RootComponent->HomeComponent
private class HomeDependencycad225e9266b3c9a56ddProvider: HomeDependencycad225e9266b3c9a56ddBaseProvider {
    init(component: NeedleFoundation.Scope) {
        super.init(rootComponent: component.parent as! RootComponent)
    }
}

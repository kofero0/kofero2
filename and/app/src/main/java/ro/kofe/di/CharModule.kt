package ro.kofe.di

import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import ro.kofe.map.CharacterMapper
import ro.kofe.model.Character
import ro.kofe.model.Move
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.ipv.character.*
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.CharProvider
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.router.RouterImpl

@Module
@InstallIn(SingletonComponent::class)
object CharModule {
    @Provides
    fun provideCharPresenter(
        charProvider: Provider<Character>,
        moveProvider: Provider<Move>,
        imageProvider: ImageProvider
    ): CharacterPresenter = CharacterPresenterImpl(charProvider, moveProvider, imageProvider)

    @Provides
    fun provideCharInteractor(
        presenter: CharacterPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: CharacterRouter
    ): CharacterInteractor = CharacterInteractorImpl(
        presenter, stateLogger, stateReducer, logger, router, DispatcherProvider.default
    )

    @Provides
    fun provideCharMapper(gson: Gson): Mapper<List<Character>, String> = CharacterMapper(gson)

    @Provides
    fun provideCharProvider(
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Character>, String>,
        requestMapper: Mapper<List<Int>, String>,
        diskAccessor: DiskAccessor
    ): Provider<Character> = CharProvider(
        HttpClientProvider.provide(),"char",urlPrefix,mapper,requestMapper,diskAccessor
    )

    @Provides
    fun provideCharacterRouter(): CharacterRouter = RouterImpl()
}
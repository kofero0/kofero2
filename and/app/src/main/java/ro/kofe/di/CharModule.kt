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
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterInteractorImpl
import ro.kofe.presenter.ipv.character.CharacterPresenter
import ro.kofe.presenter.ipv.character.CharacterPresenterImpl
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.CharProviderImpl
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

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
        logger: LoggingProvider
    ): CharacterInteractor = CharacterInteractorImpl(
        presenter, stateLogger, stateReducer, logger, DispatcherProvider.default
    )

    @Provides
    fun provideCharMapper(gson: Gson): Mapper<List<Character>, String> = CharacterMapper(gson)

    @Provides
    fun provideCharProvider(
        authProvider: AuthProvider,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Character>, String>,
        requestMapper: Mapper<List<Int>, String>,
        diskAccessor: DiskAccessor
    ): Provider<Character> = CharProviderImpl(
        HttpClientProvider.provideAuth(authProvider),
        "char",
        urlPrefix,
        mapper,
        requestMapper,
        diskAccessor
    )
}
package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import okhttp3.OkHttpClient
import ro.kofe.map.GameMapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.ipv.game.*
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.GameProviderImpl
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.LoggingProviderImpl

@Module
@InstallIn(SingletonComponent::class)
object GameModule {
    @Provides
    fun provideGameInteractor(
        presenter: GamePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider
    ): GameInteractor = GameInteractorImpl(
        presenter,
        stateLogger,
        stateReducer,
        logger,
        DispatcherProvider.default
    )

    @Provides
    fun provideGamePresenter(
        charProvider: Provider<Character>,
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider
    ): GamePresenter =
        GamePresenterImpl(charProvider, gameProvider, imageProvider, LoggingProviderImpl())

    @Provides
    fun provideGameMapper(gson: Gson): Mapper<List<Game>, String> = GameMapper(gson)

    @Provides
    fun provideGameProvider(
        authProvider: AuthProvider,
        @RootModule.UrlPrefix urlPrefix: String,
        accessor: DiskAccessor,
        mapper: Mapper<List<Game>, String>,
        requestMapper: Mapper<List<Int>, String>,
    ): Provider<Game> = GameProviderImpl(HttpClientProvider.provideAuth(authProvider),"game",urlPrefix,mapper,requestMapper,accessor)

}
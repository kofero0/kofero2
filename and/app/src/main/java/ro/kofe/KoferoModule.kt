package ro.kofe

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import dagger.hilt.android.qualifiers.ApplicationContext
import okhttp3.OkHttpClient
import ro.kofe.map.CharacterMapper
import ro.kofe.map.GameMapper
import ro.kofe.map.Mapper
import ro.kofe.map.MoveMapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.Router
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterInteractorImpl
import ro.kofe.presenter.ipv.character.CharacterPresenter
import ro.kofe.presenter.ipv.character.CharacterPresenterImpl
import ro.kofe.presenter.ipv.game.GameInteractor
import ro.kofe.presenter.ipv.game.GameInteractorImpl
import ro.kofe.presenter.ipv.game.GamePresenter
import ro.kofe.presenter.ipv.game.GamePresenterImpl
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeInteractorImpl
import ro.kofe.presenter.ipv.home.HomePresenter
import ro.kofe.presenter.ipv.home.HomePresenterImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.provider.ProviderImpl


@Module
@InstallIn(ActivityComponent::class)
object KoferoModule {

    @Provides
    fun provideUrlPrefix(): UrlPrefix {
        return UrlPrefix("http://google.com")
    }

    @Provides
    fun provideGson(): Gson {
        return Gson()
    }

    @Provides
    fun provideOkHttpClient(): OkHttpClient {
        return OkHttpClient()
    }

    @Provides
    fun provideGameMapper(gson: Gson): Mapper<List<Game>, ByteArray> {
        return GameMapper(gson)
    }

    @Provides
    fun provideCharMapper(gson: Gson): Mapper<List<Character>, ByteArray> {
        return CharacterMapper(gson)
    }

    @Provides
    fun provideMoveMapper(gson: Gson): Mapper<List<Move>, ByteArray> {
        return MoveMapper(gson)
    }

    @Provides
    fun provideGameProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        urlPrefix: UrlPrefix,
        mapper: Mapper<List<Game>, ByteArray>
    ): Provider<Game> {
        return ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
    }

    @Provides
    fun provideCharProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        urlPrefix: UrlPrefix,
        mapper: Mapper<List<Character>, ByteArray>
    ): Provider<Character> {
        return ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
    }

    @Provides
    fun provideMoveProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        urlPrefix: UrlPrefix,
        mapper: Mapper<List<Move>, ByteArray>
    ): Provider<Move> {
        return ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
    }

    @Provides
    fun provideLoggingProvider(): LoggingProvider {
        return LoggingProviderImpl()
    }

    @Provides
    fun provideRootPresenter(
        provider: Provider<Game>,
        logger: LoggingProvider
    ): RootPresenter {
        return RootPresenterImpl(provider, logger)
    }

    @Provides
    fun provideHomePresenter(
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider,
        favoritesProvider: FavoritesProvider,
        logger: LoggingProvider
    ): HomePresenter {
        return HomePresenterImpl(gameProvider, imageProvider, favoritesProvider, logger)
    }

    @Provides
    fun provideHomeInteractor(
        homePresenter: HomePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: Router
    ): HomeInteractor {
        return HomeInteractorImpl(
            homePresenter,
            stateLogger,
            stateReducer,
            logger,
            router,
            DispatcherProvider.default
        )
    }

    @Provides
    fun provideGamePresenter(
        charProvider: Provider<Character>,
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider
    ): GamePresenter {
        return GamePresenterImpl(charProvider, gameProvider, imageProvider)
    }

    @Provides
    fun provideGameInteractor(
        presenter: GamePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: Router,
    ): GameInteractor {
        return GameInteractorImpl(
            presenter,
            stateLogger,
            stateReducer,
            logger,
            router,
            DispatcherProvider.default
        )
    }

    @Provides
    fun provideCharPresenter(
        charProvider: Provider<Character>,
        moveProvider: Provider<Move>,
        imageProvider: ImageProvider
    ): CharacterPresenter {
        return CharacterPresenterImpl(charProvider, moveProvider, imageProvider)
    }

    @Provides
    fun provideCharInteractor(
        presenter: CharacterPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: Router
    ): CharacterInteractor {
        return CharacterInteractorImpl(
            presenter,
            stateLogger,
            stateReducer,
            logger,
            router,
            DispatcherProvider.default
        )
    }
}
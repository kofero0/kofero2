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
import ro.kofe.map.Mapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.game.*
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.provider.ProviderImpl
import ro.kofe.router.GameRouterImpl

@Module
@InstallIn(SingletonComponent::class)
object GameModule {
    @Provides
    fun provideGameInteractor(
        presenter: GamePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: GameRouter,
    ): GameInteractor = GameInteractorImpl(
        presenter,
        stateLogger,
        stateReducer,
        logger,
        router,
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
    fun provideGameMapper(gson: Gson): Mapper<List<Game>, ByteArray> = GameMapper(gson)

    @Provides
    fun provideGameProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Game>, ByteArray>
    ): Provider<Game> = ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)

    @Provides
    fun provideGameRouter(): GameRouter = GameRouterImpl()
}
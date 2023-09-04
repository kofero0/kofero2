package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import okhttp3.OkHttpClient
import ro.kofe.map.GameMapper
import ro.kofe.map.Mapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.game.GameInteractor
import ro.kofe.presenter.ipv.game.GameInteractorImpl
import ro.kofe.presenter.ipv.game.GamePresenter
import ro.kofe.presenter.ipv.game.GamePresenterImpl
import ro.kofe.presenter.ipv.game.GameRouter
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.ProviderImpl

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
    fun provideGamePresenter(
        charProvider: Provider<Character>,
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider
    ): GamePresenter {
        return GamePresenterImpl(charProvider, gameProvider, imageProvider)
    }

    @Provides
    fun provideGameMapper(gson: Gson): Mapper<List<Game>, ByteArray> {
        return GameMapper(gson)
    }

    @Provides
    fun provideGameProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Game>, ByteArray>
    ): Provider<Game> {
        return ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
    }
}
package ro.kofe.di

import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import okhttp3.OkHttpClient
import ro.kofe.map.FavoritesMapper
import ro.kofe.map.Mapper
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootInteractorImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.ipv.root.RootRouter
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.router.RootRouterImpl
import javax.inject.Qualifier

@Module
@InstallIn(ActivityComponent::class)
object RootModule {

    @Qualifier
    annotation class UrlPrefix

    @Provides
    @UrlPrefix
    fun provideUrlPrefix(): String {
        return "https://google.com"
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
    fun provideLoggingProvider(): LoggingProvider {
        return LoggingProviderImpl()
    }


    @Provides
    fun provideFavoritesMapper(gson: Gson): Mapper<List<Obj>, ByteArray> {
        return FavoritesMapper(gson)
    }

    @Provides
    fun provideRootPresenter(
        provider: Provider<Game>,
        logger: LoggingProvider
    ): RootPresenter {
        return RootPresenterImpl(provider, logger)
    }

    @Provides
    fun provideRootInteractor(
        presenter: RootPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: RootRouter
    ): RootInteractor {
        return RootInteractorImpl(
            presenter,stateLogger,stateReducer,logger,router,DispatcherProvider.default
        )
    }

    @Provides
    fun provideRootRouter()
    : RootRouter {
        return RootRouterImpl()
    }
}
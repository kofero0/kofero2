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
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.FavoritesProviderImpl
import ro.kofe.provider.ImageProviderImpl
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.router.RootRouterImpl
import javax.inject.Qualifier

@Module
@InstallIn(SingletonComponent::class)
object RootModule {

    @Qualifier
    annotation class UrlPrefix

    @Provides
    @UrlPrefix
    fun provideUrlPrefix(): String = "http://35.224.110.219:8080"

    @Provides
    fun provideGson(): Gson = Gson()

    @Provides
    fun provideOkHttpClient(): OkHttpClient = OkHttpClient()

    @Provides
    fun provideLoggingProvider(): LoggingProvider = LoggingProviderImpl()

    @Provides
    fun provideFavoritesMapper(gson: Gson): Mapper<List<Obj>, ByteArray> = FavoritesMapper(gson)

    @Provides
    fun provideRootPresenter(
        provider: Provider<Game>, logger: LoggingProvider
    ): RootPresenter = RootPresenterImpl(provider, logger)

    @Provides
    fun provideRootInteractor(
        presenter: RootPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: RootRouter
    ): RootInteractor = RootInteractorImpl(
        presenter, stateLogger, stateReducer, logger, router, DispatcherProvider.default
    )

    @Provides
    fun provideRootRouter(): RootRouter = RootRouterImpl()

    @Provides
    fun provideImageProvider(
        okHttpClient: OkHttpClient, @ApplicationContext context: Context
    ): ImageProvider = ImageProviderImpl(okHttpClient, context)

    @Provides
    fun provideFavoritesProvider(
        @ApplicationContext context: Context
    ): FavoritesProvider = FavoritesProviderImpl(context)

    @Provides
    fun provideDispatcherProvider() = DispatcherProvider
}
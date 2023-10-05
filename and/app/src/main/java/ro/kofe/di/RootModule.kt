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
import ro.kofe.AuthInterceptor
import ro.kofe.LoggingInterceptor
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
import ro.kofe.presenter.provider.StatusProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.AuthProvider
import ro.kofe.provider.AuthProviderImpl
import ro.kofe.provider.FavoritesProviderImpl
import ro.kofe.provider.IdentityProvider
import ro.kofe.provider.IdentityProviderImpl
import ro.kofe.provider.ImageProviderImpl
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.provider.StatusProviderImpl
import ro.kofe.router.RootRouterImpl
import javax.inject.Qualifier

@Module
@InstallIn(SingletonComponent::class)
object RootModule {

    @Qualifier
    annotation class UrlPrefix

    @Provides
    @UrlPrefix
    fun provideUrlPrefix(): String = "http://10.0.2.2:8080"

    @Provides
    fun provideGson(): Gson = Gson()

    annotation class NoAuthClient

    @Provides
    @NoAuthClient
    fun provideNoAuthClient(
        loggingInterceptor: LoggingInterceptor
    ): OkHttpClient = OkHttpClient.Builder().addInterceptor(loggingInterceptor).build()

    annotation class AuthClient

    @Provides
    @AuthClient
    fun provideAuthClient(
        loggingInterceptor: LoggingInterceptor, authInterceptor: AuthInterceptor
    ): OkHttpClient =
        OkHttpClient.Builder().addInterceptor(loggingInterceptor).addInterceptor(authInterceptor)
            .build()

    @Provides
    fun provideAuthProvider(
        gson: Gson,
        identityProvider: IdentityProvider,
        @NoAuthClient client: OkHttpClient,
        @UrlPrefix urlPrefix: String,
        @ApplicationContext context: Context
    ): AuthProvider = AuthProviderImpl(gson, identityProvider, client, urlPrefix, context)

    @Provides
    fun provideIdentityProvider(): IdentityProvider = IdentityProviderImpl()

    @Provides
    fun provideLoggingProvider(): LoggingProvider = LoggingProviderImpl()

    @Provides
    fun provideFavoritesMapper(gson: Gson): Mapper<List<Obj>, ByteArray> = FavoritesMapper(gson)

    @Provides
    fun provideRootPresenter(
        logger: LoggingProvider, provider: StatusProvider
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

    @Provides
    fun provideStatusProvider(
        okHttpClient: OkHttpClient, @UrlPrefix prefix: String, gson: Gson
    ): StatusProvider = StatusProviderImpl(okHttpClient, prefix, gson)
}
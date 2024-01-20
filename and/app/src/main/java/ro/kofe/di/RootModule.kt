package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import okhttp3.OkHttpClient
import ro.kofe.AuthInterceptor
import ro.kofe.LoggingInterceptor
import ro.kofe.map.RequestMapper
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.root.*
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.StatusProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.*
import ro.kofe.router.RouterImpl
import javax.inject.Qualifier

@Module
@InstallIn(SingletonComponent::class)
object RootModule {

    @Qualifier
    annotation class UrlPrefix

    @Provides
    fun provideRequestMapper(gson: Gson): Mapper<List<Int>, String> = RequestMapper(gson)

    @Provides
    @UrlPrefix
    fun provideUrlPrefix(): String = "http://10.0.2.2:8080"

    @Provides
    fun provideGson(): Gson = Gson()

    @Provides
    fun provideOkHttpClient(
        loggingInterceptor: LoggingInterceptor, authInterceptor: AuthInterceptor
    ) = OkHttpClient.Builder().addInterceptor(loggingInterceptor).addInterceptor(authInterceptor)
        .build()

    @Provides
    fun provideAuthProvider(
        gson: Gson,
        identityProvider: IdentityProvider,
        loggingInterceptor: LoggingInterceptor,
        @UrlPrefix urlPrefix: String,
        @ApplicationContext context: Context
    ): AuthProvider = AuthProviderImpl(
        gson,
        identityProvider,
        OkHttpClient.Builder().addInterceptor(loggingInterceptor).build(),
        urlPrefix,
        context
    )

    @Provides
    fun provideLoggingInterceptor(
        logger: LoggingProvider
    ) = LoggingInterceptor(logger)

    @Provides
    fun provideAuthInterceptor(
        authProvider: AuthProvider,
        dispatcherProvider: DispatcherProvider,
        logger: LoggingProvider
    ) = AuthInterceptor(authProvider, dispatcherProvider, logger)

    @Provides
    fun provideIdentityProvider(): IdentityProvider = IdentityProviderImpl()

    @Provides
    fun provideLoggingProvider(): LoggingProvider = LoggingProviderImpl()

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
    fun provideRootRouter(): RootRouter = RouterImpl()

    @Provides
    fun provideImageProvider(
        okHttpClient: OkHttpClient, @ApplicationContext context: Context
    ): ImageProvider = ImageProviderImpl(okHttpClient, context)

    @Provides
    fun provideFavoritesProvider(
        @ApplicationContext context: Context,
        gson: Gson
    ): FavoritesProvider = FavoritesProviderImpl(context,gson)

    @Provides
    fun provideDispatcherProvider() = DispatcherProvider

    @Provides
    fun provideStatusProvider(
        okHttpClient: OkHttpClient, @UrlPrefix prefix: String, gson: Gson
    ): StatusProvider = StatusProviderImpl(okHttpClient, prefix, gson)
}
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
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootInteractorImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.provider.StatusProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.AuthProviderImpl
import ro.kofe.provider.DiskAccessorImpl
import ro.kofe.provider.FavoritesProviderImpl
import ro.kofe.provider.IdentityProvider
import ro.kofe.provider.IdentityProviderImpl
import ro.kofe.provider.ImageProviderImpl
import ro.kofe.provider.StatusProviderImpl
import javax.inject.Qualifier

@Module
@InstallIn(SingletonComponent::class)
object RootModule {

    @Qualifier
    annotation class UrlPrefix

    @Qualifier
    annotation class AuthClient

    @Qualifier
    annotation class NoAuthClient

    @Provides
    @AuthClient
    fun provideAuthClient(authProvider: AuthProvider) = HttpClientProvider.provideAuth(authProvider)

    @Provides
    @NoAuthClient
    fun provideNoAuthClient() = HttpClientProvider.provideNoAuth()

    @Provides
    fun provideRequestMapper(gson: Gson): Mapper<List<Int>, String> = RequestMapper(gson)

    @Provides
    fun provideDiskAccessor(@ApplicationContext context: Context): DiskAccessor =
        DiskAccessorImpl(context)

    @Provides
    @UrlPrefix
    fun provideUrlPrefix(): String = "https://kofero.org"

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
    fun provideRootPresenter(
        loggingProvider: LoggingProvider,
        statusProvider: StatusProvider,
        authProvider: AuthProvider,
        gameProvider: Provider<Game>,
        charProvider: Provider<Character>,
        moveProvider: Provider<Move>
    ): RootPresenter = RootPresenterImpl(
        statusProvider,
        authProvider,
        gameProvider,
        charProvider,
        moveProvider,
        loggingProvider
    )

    @Provides
    fun provideRootInteractor(
        presenter: RootPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider
    ): RootInteractor = RootInteractorImpl(
        presenter, stateLogger, stateReducer, logger, DispatcherProvider
    )

    @Provides
    fun provideImageProvider(
        okHttpClient: OkHttpClient, @ApplicationContext context: Context
    ): ImageProvider = ImageProviderImpl(okHttpClient, context)

    @Provides
    fun provideFavoritesProvider(
        @ApplicationContext context: Context,
        gson: Gson
    ): FavoritesProvider = FavoritesProviderImpl(context, gson)

    @Provides
    fun provideDispatcherProvider() = DispatcherProvider

    @Provides
    fun provideStatusProvider(
        okHttpClient: OkHttpClient, @UrlPrefix prefix: String, gson: Gson
    ): StatusProvider = StatusProviderImpl(okHttpClient, prefix, gson)
}
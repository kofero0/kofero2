package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import io.ktor.client.HttpClient
import okhttp3.OkHttpClient
import ro.kofe.AuthInterceptor
import ro.kofe.LoggingInterceptor
import ro.kofe.map.AuthMapperImpl
import ro.kofe.map.CopyMapper
import ro.kofe.map.QueryMapper
import ro.kofe.map.RequestMapper
import ro.kofe.map.StatusMapper
import ro.kofe.model.Character
import ro.kofe.model.Copy
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootInteractorImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthDiskAccessor
import ro.kofe.presenter.provider.AuthMapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.AuthProviderImpl
import ro.kofe.presenter.provider.CopyProvider
import ro.kofe.presenter.provider.CopyProviderImpl
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.IdentityProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.ImageProviderImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.provider.StatusProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.ConcreteStatusProvider
import ro.kofe.provider.DiskAccessorImpl
import ro.kofe.provider.FavoritesProviderImpl
import ro.kofe.provider.IdentityProviderImpl
import ro.kofe.provider.StatusProviderDiskAccessor
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
    fun provideAuthDiskAccessor(@ApplicationContext context: Context): AuthDiskAccessor =
        DiskAccessorImpl(context)

    @Provides
    fun provideAuthMapper(gson: Gson): AuthMapper = AuthMapperImpl(gson)

    @Provides
    fun provideGson(): Gson = Gson()

    @Provides
    fun provideOkHttpClient(
        loggingInterceptor: LoggingInterceptor, authInterceptor: AuthInterceptor
    ) = OkHttpClient.Builder().addInterceptor(loggingInterceptor).addInterceptor(authInterceptor)
        .build()

    @Provides
    fun provideAuthProvider(
        @NoAuthClient client: HttpClient,
        authDiskAccessor: AuthDiskAccessor,
        authMapper: AuthMapper,
        identityProvider: IdentityProvider,
        @UrlPrefix urlPrefix: String
    ): AuthProvider =
        AuthProviderImpl(client, urlPrefix, authDiskAccessor, authMapper, identityProvider)

    @Provides
    fun provideQueryMapper(): Mapper<List<String>, String> = QueryMapper()

    @Provides
    fun provideLoggingInterceptor(
        logger: LoggingProvider
    ) = LoggingInterceptor(logger)

    @Provides
    fun provideAuthInterceptor(
        authProvider: AuthProvider, dispatcherProvider: DispatcherProvider, logger: LoggingProvider
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
        moveProvider: Provider<Move>,
        copyProvider: CopyProvider
    ): RootPresenter = RootPresenterImpl(
        statusProvider,
        authProvider,
        gameProvider,
        charProvider,
        moveProvider,
        copyProvider,
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
        @NoAuthClient httpClient: HttpClient, diskAccessor: DiskAccessor
    ): ImageProvider = ImageProviderImpl(httpClient, diskAccessor)

    @Provides
    fun provideFavoritesProvider(
        @ApplicationContext context: Context, gson: Gson
    ): FavoritesProvider = FavoritesProviderImpl(context, gson)

    @Provides
    fun provideDispatcherProvider() = DispatcherProvider

    @Provides
    fun provideStatusProvider(
        @NoAuthClient httpClient: HttpClient,
        @UrlPrefix urlPrefix: String,
        @ApplicationContext context: Context,
        gson: Gson
    ): StatusProvider = ConcreteStatusProvider(
        httpClient, urlPrefix, StatusMapper(gson), StatusProviderDiskAccessor(context, gson)
    )

    @Provides
    fun provideCopyProvider(
        @AuthClient httpClient: HttpClient,
        @UrlPrefix prefix: String,
        gson: Gson,
        @ApplicationContext context: Context
    ): CopyProvider = CopyProviderImpl(
        httpClient, "copy", prefix, CopyMapper(gson), DiskAccessorImpl(
            context, gson.toJson(
                Copy("", "", "")
            )
        )
    )
}
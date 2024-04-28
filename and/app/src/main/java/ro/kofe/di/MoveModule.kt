package ro.kofe.di

import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import ro.kofe.map.MoveMapper
import ro.kofe.model.Move
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.MoveProviderImpl
import ro.kofe.presenter.provider.Provider

@Module
@InstallIn(SingletonComponent::class)
object MoveModule {
    @Provides
    fun provideMoveMapper(gson: Gson): Mapper<List<Move>, String> = MoveMapper(gson)

    @Provides
    fun provideMoveProvider(
        authProvider: AuthProvider,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Move>, String>,
        requestMapper: Mapper<List<Int>, String>,
        queryMapper: Mapper<List<String>, String>,
        diskAccessor: DiskAccessor
    ): Provider<Move> = MoveProviderImpl(
        HttpClientProvider.provideAuth(authProvider),
        "move",
        urlPrefix,
        mapper,
        queryMapper,
        requestMapper,
        diskAccessor
    )
}
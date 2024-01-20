package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import okhttp3.OkHttpClient
import ro.kofe.map.MoveMapper
import ro.kofe.model.Move
import ro.kofe.presenter.HttpClientProvider
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.MoveProvider
import ro.kofe.presenter.provider.Provider

@Module
@InstallIn(SingletonComponent::class)
object MoveModule {
    @Provides
    fun provideMoveMapper(gson: Gson): Mapper<List<Move>, String> = MoveMapper(gson)

    @Provides
    fun provideMoveProvider(
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Move>, String>,
        requestMapper: Mapper<List<Int>, String>,
        diskAccessor: DiskAccessor
    ): Provider<Move> = MoveProvider(HttpClientProvider.provide(),"move",urlPrefix,mapper,requestMapper,diskAccessor)
}
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
import ro.kofe.map.Mapper
import ro.kofe.map.MoveMapper
import ro.kofe.model.Move
import ro.kofe.presenter.provider.Provider
import ro.kofe.provider.ProviderImpl

@Module
@InstallIn(SingletonComponent::class)
object MoveModule {
    @Provides
    fun provideMoveMapper(gson: Gson): Mapper<List<Move>, ByteArray> {
        return MoveMapper(gson)
    }

    @Provides
    fun provideMoveProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Move>, ByteArray>
    ): Provider<Move> {
        return ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
    }
}
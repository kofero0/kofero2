package ro.kofe

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import dagger.hilt.android.qualifiers.ApplicationContext
import okhttp3.OkHttpClient
import ro.kofe.map.CharacterMapper
import ro.kofe.map.GameMapper
import ro.kofe.map.Mapper
import ro.kofe.map.MoveMapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move


@Module
@InstallIn(ActivityComponent::class)
object KoferoModule {
    @Provides
    fun provideGson(): Gson {
        return Gson()
    }

    @Provides
    fun provideOkHttpClient(): OkHttpClient {
        return OkHttpClient()
    }

    @Provides
    fun provideGameMapper(gson: Gson): Mapper<List<Game>, ByteArray> {
        return GameMapper(gson)
    }

    @Provides
    fun provideCharMapper(gson: Gson): Mapper<List<Character>, ByteArray> {
        return CharacterMapper(gson)
    }

    @Provides
    fun provideMoveMapper(gson: Gson): Mapper<List<Move>, ByteArray> {
        return MoveMapper(gson)
    }

    @Provides
    fun provideGameProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        mapper: Mapper<List<Game>, ByteArray>
    ): Provider<Game> {
        return Provider(gson,okHttp,context,"game",mapper)
    }

    @Provides
    fun provideCharProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        mapper: Mapper<List<Character>, ByteArray>
    ): Provider<Character> {
        return Provider(gson,okHttp,context,"game",mapper)
    }

    @Provides
    fun provideMoveProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        mapper: Mapper<List<Move>, ByteArray>
    ): Provider<Move> {
        return Provider(gson,okHttp,context,"game",mapper)
    }
}
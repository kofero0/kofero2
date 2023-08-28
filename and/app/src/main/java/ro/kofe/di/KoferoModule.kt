package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import dagger.hilt.android.qualifiers.ApplicationContext
import okhttp3.OkHttpClient
import ro.kofe.UrlPrefix
import ro.kofe.map.CharacterMapper
import ro.kofe.map.FavoritesMapper
import ro.kofe.map.GameMapper
import ro.kofe.map.Mapper
import ro.kofe.map.MoveMapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.model.Obj
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.Router
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterInteractorImpl
import ro.kofe.presenter.ipv.character.CharacterPresenter
import ro.kofe.presenter.ipv.character.CharacterPresenterImpl
import ro.kofe.presenter.ipv.game.GameInteractor
import ro.kofe.presenter.ipv.game.GameInteractorImpl
import ro.kofe.presenter.ipv.game.GamePresenter
import ro.kofe.presenter.ipv.game.GamePresenterImpl
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeInteractorImpl
import ro.kofe.presenter.ipv.home.HomePresenter
import ro.kofe.presenter.ipv.home.HomePresenterImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.LoggingProviderImpl
import ro.kofe.provider.ProviderImpl


@Module
@InstallIn(ActivityComponent::class)
object KoferoModule {
    @Provides
    fun provideUrlPrefix(): UrlPrefix {
        return UrlPrefix("http://google.com")
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
}
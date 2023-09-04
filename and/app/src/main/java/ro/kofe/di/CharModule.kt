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
import ro.kofe.map.CharacterMapper
import ro.kofe.map.Mapper
import ro.kofe.model.Character
import ro.kofe.model.Move
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterInteractorImpl
import ro.kofe.presenter.ipv.character.CharacterPresenter
import ro.kofe.presenter.ipv.character.CharacterPresenterImpl
import ro.kofe.presenter.ipv.character.CharacterRouter
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.ProviderImpl

@Module
@InstallIn(SingletonComponent::class)
object CharModule {
    @Provides
    fun provideCharPresenter(
        charProvider: Provider<Character>,
        moveProvider: Provider<Move>,
        imageProvider: ImageProvider
    ): CharacterPresenter = CharacterPresenterImpl(charProvider, moveProvider, imageProvider)

    @Provides
    fun provideCharInteractor(
        presenter: CharacterPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: CharacterRouter
    ): CharacterInteractor = CharacterInteractorImpl(
        presenter, stateLogger, stateReducer, logger, router, DispatcherProvider.default
    )

    @Provides
    fun provideCharMapper(gson: Gson): Mapper<List<Character>, ByteArray> = CharacterMapper(gson)

    @Provides
    fun provideCharProvider(
        gson: Gson,
        okHttp: OkHttpClient,
        @ApplicationContext context: Context,
        @RootModule.UrlPrefix urlPrefix: String,
        mapper: Mapper<List<Character>, ByteArray>
    ): Provider<Character> = ProviderImpl(gson, okHttp, context, "game", urlPrefix, mapper)
}
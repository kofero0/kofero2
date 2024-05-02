package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import io.ktor.client.HttpClient
import ro.kofe.map.CopyMapper
import ro.kofe.model.Copy
import ro.kofe.model.Game
import ro.kofe.model.Status
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeInteractorImpl
import ro.kofe.presenter.ipv.home.HomePresenter
import ro.kofe.presenter.ipv.home.HomePresenterImpl
import ro.kofe.presenter.provider.CopyProvider
import ro.kofe.presenter.provider.CopyProviderImpl
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.provider.DiskAccessorImpl

@Module
@InstallIn(SingletonComponent::class)
object HomeModule {
    @Provides
    fun provideHomePresenter(
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider,
        favoritesProvider: FavoritesProvider,
        logger: LoggingProvider
    ): HomePresenter =
        HomePresenterImpl(gameProvider, imageProvider, favoritesProvider, logger)


    @Provides
    fun provideHomeInteractor(
        homePresenter: HomePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider
    ): HomeInteractor = HomeInteractorImpl(
        homePresenter,
        stateLogger,
        stateReducer,
        logger,
        DispatcherProvider.default
    )

}
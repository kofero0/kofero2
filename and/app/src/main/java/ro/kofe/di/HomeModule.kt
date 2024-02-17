package ro.kofe.di

import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import ro.kofe.map.RequestMapper
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.home.*
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

@Module
@InstallIn(SingletonComponent::class)
object HomeModule {
    @Provides
    fun provideHomePresenter(
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider,
        favoritesProvider: FavoritesProvider,
        logger: LoggingProvider
    ): HomePresenter = HomePresenterImpl(gameProvider, imageProvider, favoritesProvider, logger)

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
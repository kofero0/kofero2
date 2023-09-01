package ro.kofe.di

import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeInteractorImpl
import ro.kofe.presenter.ipv.home.HomePresenter
import ro.kofe.presenter.ipv.home.HomePresenterImpl
import ro.kofe.presenter.ipv.home.HomeRouter
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

@Module
@InstallIn(ActivityComponent::class)
object HomeModule {
    @Provides
    fun provideHomePresenter(
        gameProvider: Provider<Game>,
        imageProvider: ImageProvider,
        favoritesProvider: FavoritesProvider,
        logger: LoggingProvider
    ): HomePresenter {
        return HomePresenterImpl(gameProvider, imageProvider, favoritesProvider, logger)
    }

    @Provides
    fun provideHomeInteractor(
        homePresenter: HomePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: HomeRouter
    ): HomeInteractor {
        return HomeInteractorImpl(
            homePresenter,
            stateLogger,
            stateReducer,
            logger,
            router,
            DispatcherProvider.default
        )
    }

}
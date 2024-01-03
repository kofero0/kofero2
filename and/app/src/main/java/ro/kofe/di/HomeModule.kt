package ro.kofe.di

import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.home.*
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.router.HomeRouterImpl

@Module
@InstallIn(SingletonComponent::class)
object HomeModule {
    @Provides
    fun provideHomePresenter(
        gameProvider: Provider<Game>,
        charProvider: Provider<Character>,
        imageProvider: ImageProvider,
        favoritesProvider: FavoritesProvider,
        logger: LoggingProvider
    ): HomePresenter = HomePresenterImpl(gameProvider, charProvider, imageProvider, favoritesProvider, logger)

    @Provides
    fun provideHomeInteractor(
        homePresenter: HomePresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: HomeRouter
    ): HomeInteractor = HomeInteractorImpl(
        homePresenter,
        stateLogger,
        stateReducer,
        logger,
        router,
        DispatcherProvider.default
    )

    @Provides
    fun provideHomeRouter(): HomeRouter = HomeRouterImpl()
}
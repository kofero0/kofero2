package ro.kofe.di

import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.Router
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootInteractorImpl
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.ipv.root.RootPresenterImpl
import ro.kofe.presenter.ipv.root.RootRouter
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

@Module
@InstallIn(ActivityComponent::class)
object RootModule {
    @Provides
    fun provideRootPresenter(
        provider: Provider<Game>,
        logger: LoggingProvider
    ): RootPresenter {
        return RootPresenterImpl(provider, logger)
    }

    @Provides
    fun provideRootInteractor(
        presenter: RootPresenter,
        stateLogger: StateLogger,
        stateReducer: StateReducer,
        logger: LoggingProvider,
        router: RootRouter
    ): RootInteractor {
        return RootInteractorImpl(
            presenter,stateLogger,stateReducer,logger,router,DispatcherProvider.default
        )
    }
}
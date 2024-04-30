package ro.kofe.presenter.ipv.about

import ro.kofe.model.logging.LogTag.ABOUT_INTERACTOR
import ro.kofe.presenter.ipv.Interactor
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

interface AboutInteractor: Interactor<AboutKView>

class AboutInteractorImpl(presenter: AboutPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider): AboutInteractor, InteractorImpl<AboutKView,AboutPresenter>(
        presenter,
        stateLogger,
        stateReducer,
        loggingProvider,
        ABOUT_INTERACTOR
    ){

    }
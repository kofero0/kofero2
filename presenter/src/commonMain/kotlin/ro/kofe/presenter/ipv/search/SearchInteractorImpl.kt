package ro.kofe.presenter.ipv.search

import kotlinx.coroutines.DelicateCoroutinesApi
import ro.kofe.model.logging.LogTag.SEARCH_INTERACTOR
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.ipv.root.RootKView
import ro.kofe.presenter.ipv.root.RootPresenter
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

@OptIn(DelicateCoroutinesApi::class)
class SearchInteractorImpl(
    presenter: SearchPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider,
    private val dispatcherProvider: DispatcherProvider
): InteractorImpl<SearchKView, SearchPresenter>(
    presenter,
    stateLogger,
    stateReducer,
    loggingProvider,
    SEARCH_INTERACTOR
){

}
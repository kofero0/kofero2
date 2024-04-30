package ro.kofe.presenter.ipv.search

import ro.kofe.model.logging.Level
import ro.kofe.model.logging.LogTag.SEARCH_INTERACTOR
import ro.kofe.presenter.ipv.Interactor
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer


interface SearchInteractor : Interactor<SearchKView> {
    suspend fun search(query:List<String>)
}

class SearchInteractorImpl(
    presenter: SearchPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    private val loggingProvider: LoggingProvider
) : SearchInteractor, InteractorImpl<SearchKView, SearchPresenter>(
    presenter, stateLogger, stateReducer, loggingProvider, SEARCH_INTERACTOR
) {
    override suspend fun search(query: List<String>) = presenter.search(query).collect {
        loggingProvider.log(Level.ALERT, SEARCH_INTERACTOR, "search error: $it")
    }
}
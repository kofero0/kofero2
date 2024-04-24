package ro.kofe.presenter.ipv.search

import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.ProviderError
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.model.logging.LogTag.SEARCH_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.ipv.root.RootKView
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider

class SearchPresenterImpl(
    private val gameProvider: Provider<Game>,
    private val charProvider: Provider<Character>,
    loggingProvider: LoggingProvider
): SearchPresenter, PresenterImpl<SearchKView>(null, loggingProvider, SEARCH_PRESENTER) {

    override fun setView(view: SearchKView) {
        this.view = view
    }

    override suspend fun search(query: List<String>) = flow {
        gameProvider.search(query).collect{ either ->
            either.map {
                
            }
        }
        charProvider.search(query).collect{ either ->

        }
    }

}
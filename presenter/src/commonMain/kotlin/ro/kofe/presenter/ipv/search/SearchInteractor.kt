package ro.kofe.presenter.ipv.search

import ro.kofe.presenter.ipv.Interactor
import ro.kofe.presenter.ipv.root.RootKView


interface SearchInteractor : Interactor<SearchKView> {
    suspend fun search(query:List<String>)
}
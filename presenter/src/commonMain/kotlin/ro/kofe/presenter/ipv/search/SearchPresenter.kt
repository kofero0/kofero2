package ro.kofe.presenter.ipv.search

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface SearchPresenter: Presenter<SearchKView>{
    suspend fun search(query:List<String>): Flow<ProviderError>
}
package ro.kofe.presenter.ipv.home

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter
import ro.kofe.presenter.provider.Provider

interface HomePresenter : Presenter<HomeKView> {
    suspend fun showGames(): Flow<ProviderError>
    suspend fun showFavs(): Flow<ProviderError>
    suspend fun showCopy(): Flow<ProviderError>
}
package ro.kofe.presenter.ipv.game

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface GamePresenter : Presenter<GameKView> {
    suspend fun showGame(id: Int): Flow<ProviderError>
}
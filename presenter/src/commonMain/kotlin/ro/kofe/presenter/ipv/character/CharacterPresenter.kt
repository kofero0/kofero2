package ro.kofe.presenter.ipv.character

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface CharacterPresenter : Presenter<CharacterKView> {
    suspend fun showChar(id: Int): Flow<ProviderError>
}
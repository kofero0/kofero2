package ro.kofe.presenter.ipv.character

import arrow.core.Either
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface CharacterPresenter : Presenter<CharacterView> {
    suspend fun showChar(id: Int): Either<ProviderError, Unit>
}
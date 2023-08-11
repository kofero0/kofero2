package ro.kofe.presenter.ipv.game

import arrow.core.Either
import ro.kofe.model.Error
import ro.kofe.presenter.ipv.Presenter

interface GamePresenter : Presenter<GameView> {
    suspend fun showGame(id: Int): Either<Error, Unit>
}
package ro.kofe.presenter.ipv.game

import ro.kofe.model.Character
import ro.kofe.presenter.ipv.Interactor

interface GameInteractor : Interactor<GameKView> {
   suspend fun charPressed(char: Character)
   suspend fun setGameUid(uid: Int)
}
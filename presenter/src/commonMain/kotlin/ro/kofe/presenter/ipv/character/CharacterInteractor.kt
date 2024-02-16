package ro.kofe.presenter.ipv.character

import ro.kofe.presenter.ipv.Interactor

interface CharacterInteractor : Interactor<CharacterKView> {
    suspend fun setUids(charUid: Int, gameUid: Int)
}
package ro.kofe.presenter.ipv.character

import ro.kofe.presenter.ipv.Interactor

interface CharacterInteractor : Interactor<CharacterKView> {
    suspend fun setCharUid(uid: Int)
}
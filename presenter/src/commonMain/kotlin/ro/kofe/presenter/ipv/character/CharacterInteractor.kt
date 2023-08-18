package ro.kofe.presenter.ipv.character

import ro.kofe.presenter.ipv.Interactor

interface CharacterInteractor : Interactor<CharacterKView> {
    fun setCharUid(uid: Int)
}
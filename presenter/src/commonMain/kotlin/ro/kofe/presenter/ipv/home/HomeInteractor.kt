package ro.kofe.presenter.ipv.home

import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.ipv.Interactor

interface HomeInteractor : Interactor<HomeKView> {
    suspend fun favPressed(obj: Obj)
    suspend fun gamePressed(game: Game)
}
package ro.kofe.presenter.ipv.home

import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.Interactor

interface HomeInteractor : Interactor<HomeKView> {
    suspend fun favPressed(fav: Favorite)
    suspend fun gamePressed(game: Game)
}
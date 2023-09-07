package ro.kofe.presenter.ipv.home

import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.ipv.ImageKView

interface HomeKView : ImageKView {
    fun displayGames(games: List<Game>)
    fun displayFavs(favorites: List<Obj>)
    fun displayGamesError(error: Error)
    fun displayFavsError(error: Error)
}
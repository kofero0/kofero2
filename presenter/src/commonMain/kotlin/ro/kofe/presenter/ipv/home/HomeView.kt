package ro.kofe.presenter.ipv.home

import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.ipv.KView

interface HomeView : KView {
    fun displayGames(games: List<Game>)
    fun displayFavs(favorites: List<Obj>)
    fun display(url: String, imgBase64: String)
    fun displayGamesError(error:Error)
    fun displayFavsError(error:Error)
}
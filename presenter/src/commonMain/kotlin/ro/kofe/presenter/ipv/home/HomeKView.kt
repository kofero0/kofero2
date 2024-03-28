package ro.kofe.presenter.ipv.home

import ro.kofe.model.Copy
import ro.kofe.model.Error
import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.ImageKView

interface HomeKView : ImageKView {
    fun displayGames(games: List<Game>)
    fun displayFavs(favorites: List<Favorite>)
    fun displayCopy(copy: Copy)
    fun displayGamesError(error: Error)
    fun displayFavsError(error: Error)
}
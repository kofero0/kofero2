package ro.kofe.view

import androidx.fragment.app.Fragment
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeKView

class HomeFragment(
    private val interactor: HomeInteractor
): HomeKView, Fragment() {

    init{
        interactor.setView(this)
    }


    override fun display(url: String, imgBase64: String) {
        TODO("Not yet implemented")
    }

    override fun displayFavs(favorites: List<Obj>) {
        TODO("Not yet implemented")
    }

    override fun displayFavsError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun displayGames(games: List<Game>) {
        TODO("Not yet implemented")
    }

    override fun displayGamesError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }
}
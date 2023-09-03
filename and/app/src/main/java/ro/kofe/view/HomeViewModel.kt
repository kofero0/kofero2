package ro.kofe.view

import androidx.lifecycle.ViewModel
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeKView
import javax.inject.Inject

@HiltViewModel
class HomeViewModel @Inject constructor(private val interactor: HomeInteractor) : HomeKView,
    ViewModel() {
    init {
        interactor.setView(this)
    }

    private val _images = MutableStateFlow<MutableMap<String, String>>(HashMap())
    val images = _images.asStateFlow()

    private val _favs = MutableStateFlow<List<Obj>>(ArrayList())
    val favs = _favs.asStateFlow()

    private val _games = MutableStateFlow<List<Game>>(ArrayList())
    val games = _games.asStateFlow()

    fun onStart() {
        interactor.viewResumed()
    }

    fun onStop() {
        interactor.viewPaused()
    }

    override fun display(url: String, imgBase64: String) {
        _images.update {
            _images.value.apply { put(url, imgBase64) }
        }
    }

    override fun displayFavs(favorites: List<Obj>) {
        _favs.update {
            favorites
        }
    }

    override fun displayFavsError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun displayGames(games: List<Game>) {
        _games.update {
            games
        }
    }

    override fun displayGamesError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }


}
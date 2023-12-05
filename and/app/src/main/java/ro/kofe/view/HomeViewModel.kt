package ro.kofe.view

import android.util.Log
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Obj
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.home.HomeInteractor
import ro.kofe.presenter.ipv.home.HomeKView
import javax.inject.Inject

@HiltViewModel
class HomeViewModel @Inject constructor(
    private val interactor: HomeInteractor
) : HomeKView, ImageViewModel(interactor) {
    init {
        interactor.setView(this)
    }

    private val _favs = MutableStateFlow<List<Obj>>(ArrayList())
    val favs = _favs.asStateFlow()

    private val _games = MutableStateFlow<List<Game>>(ArrayList())
    val games = _games.asStateFlow()

    private val _favError = MutableStateFlow<Error?>(null)
    val favError = _favError.asStateFlow()

    private val _gameError = MutableStateFlow<Error?>(null)
    val gameError = _gameError.asStateFlow()

    fun favPressed(obj: Obj) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.favPressed(obj)
    }

    fun gamePressed(game: Game) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.gamePressed(game)
    }

    override fun displayFavs(favorites: List<Obj>) = _favs.update {
        favorites
    }

    override fun displayFavsError(error: Error) = _favError.update { error }

    override fun displayGames(games: List<Game>) = _games.update {
        Log.v("rwr", "games: $games")
        games
    }

    override fun displayGamesError(error: Error) = _gameError.update { error }

    override fun error(e: Exception) = super.error(e)
}
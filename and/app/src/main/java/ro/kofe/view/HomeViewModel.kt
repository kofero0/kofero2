package ro.kofe.view

import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import ro.kofe.model.Error
import ro.kofe.model.Favorite
import ro.kofe.model.Game
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

    private val _favs = MutableStateFlow<List<Favorite>>(ArrayList())
    val favs = _favs.asStateFlow()

    private val _games = MutableStateFlow<List<Game>>(ArrayList())
    val games = _games.asStateFlow()

    private val _favError = MutableStateFlow<Error?>(null)
    val favError = _favError.asStateFlow()

    private val _gameError = MutableStateFlow<Error?>(null)
    val gameError = _gameError.asStateFlow()

    fun favPressed(fav: Favorite) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.favPressed(fav)
    }

    fun gamePressed(game: Game) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.gamePressed(game)
    }

    override fun displayFavsError(error: Error) = _favError.update { error }

    override fun displayGames(games: List<Game>) = _games.update {
        games
    }

    override fun displayFavs(favorites: List<Favorite>)  = _favs.update {
        favorites
    }

    override fun displayGamesError(error: Error) = _gameError.update { error }

    override fun error(e: Exception) = super.error(e)
}
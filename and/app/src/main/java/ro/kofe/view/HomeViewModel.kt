package ro.kofe.view

import android.util.Log
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import ro.kofe.model.Copy
import ro.kofe.model.Error
import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.model.Sort
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

    private val _copy = MutableStateFlow<Copy?>(null)
    val copy = _copy.asStateFlow()

    fun favPressed(fav: Favorite) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.favPressed(fav)
    }

    fun gamePressed(game: Game) = CoroutineScope(DispatcherProvider.default).launch {
        interactor.gamePressed(game)
    }

    fun sortGames(sortOn: Sort, direction: Sort.Direction) =
        CoroutineScope(DispatcherProvider.default).launch {
            var sorted = when (sortOn) {
                Sort.RELEASE_DATE -> {
                    games.value.sortedWith { game0, game1 -> game0.date.compareTo(game1.date) }
                }

                Sort.NAME -> {
                    games.value.sortedWith { game0, game1 -> game0.name.compareTo(game1.name) }
                }
            }
            if (direction == Sort.Direction.ASCENDING) {
                sorted = sorted.reversed()
            }
            displayGames(sorted)
        }

    fun sortFavs(sortOn: Sort, direction: Sort.Direction) =
        CoroutineScope(DispatcherProvider.default).launch {
            var sorted = when (sortOn) {
                Sort.RELEASE_DATE -> {
                    favs.value.sortedWith { fav0, fav1 ->
                        val date0 = if (fav0.character == null) {
                            fav0.game.date
                        } else {
                            fav0.character!!.date
                        }
                        val date1 = if (fav1.character == null) {
                            fav1.game.date
                        } else {
                            fav1.character!!.date
                        }
                        date0.compareTo(date1)
                    }
                }

                Sort.NAME -> {
                    favs.value.sortedWith { fav0, fav1 ->
                        val name0 = if (fav0.character == null) {
                            fav0.game.name
                        } else {
                            fav0.character!!.name
                        }
                        val name1 = if (fav1.character == null) {
                            fav1.game.name
                        } else {
                            fav1.character!!.name
                        }
                        name0.compareTo(name1)
                    }
                }
            }
            if (direction == Sort.Direction.ASCENDING) {
                sorted = sorted.reversed()
            }
            displayFavs(sorted)
        }

    override fun displayFavsError(error: Error) = _favError.update { error }

    override fun displayGames(games: List<Game>) = _games.update {
        games
    }

    override fun displayFavs(favorites: List<Favorite>) = _favs.update {
        favorites
    }

    override fun displayCopy(inCopy: Copy) = _copy.update { inCopy }

    override fun displayGamesError(error: Error) = _gameError.update { error }

    override fun error(e: Exception) = super.error(e)
}
package ro.kofe.view

import androidx.lifecycle.ViewModel
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.ProviderError
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.Provider
import javax.inject.Inject

@HiltViewModel
class AppBarViewModel @Inject constructor(
    private val favsProvider: FavoritesProvider,
    private val gameProvider: Provider<Game>,
    private val charProvider: Provider<Character>,
    private val dispatcherProvider: DispatcherProvider
) : ViewModel() {
    private val _title = MutableStateFlow(DEFAULT_TITLE)
    val title = _title.asStateFlow()

    private val _canNavigateBack = MutableStateFlow(false)
    val canNavigateBack = _canNavigateBack.asStateFlow()

    private val _favoriteClicked = MutableStateFlow {}
    val favoriteClicked = _favoriteClicked.asStateFlow()

    private val _navClicked = MutableStateFlow {}
    val navClicked = _navClicked.asStateFlow()

    private val _canFavorite = MutableStateFlow(false)
    val canFavorite = _canFavorite.asStateFlow()

    private val _isFavorited = MutableStateFlow(false)
    val isFavorited = _isFavorited.asStateFlow()

    private val _error = MutableStateFlow<ProviderError?>(null)
    val error = _error.asStateFlow()

    private var backStackClosure: (() -> Unit)? = null

    fun setBackStackClosure(closure: () -> Unit) {
        backStackClosure = closure
        _navClicked.update { { backStackClosure?.invoke() } }
    }

    private fun toHome() {
        _canFavorite.update { false }
        _title.update { DEFAULT_TITLE }
        _canNavigateBack.update { false }
    }

    fun fromHome(uid: Int) {
        CoroutineScope(dispatcherProvider.default).launch {
            favsProvider.get().fold({ error ->
                _error.update { error }
            }) { favs ->
                _isFavorited.update { favs.any { it.uid == uid } }
                _canFavorite.update { true }
                gameProvider.get(ArrayList<Int>().apply { add(uid) }).collect { gameEither ->
                    gameEither.fold({
                        charProvider.get(ArrayList<Int>().apply { add(uid) })
                            .collect { charEither ->
                                charEither.fold({
                                    _error.update { it }
                                }) { chars ->
                                    _title.update { chars.first { char -> char.uid == uid }.name }
                                }
                            }
                    }) { games ->
                        _title.update { games.first { game -> game.uid == uid }.name }
                    }
                }
            }
        }
        _canNavigateBack.update { true }
        _navClicked.update {
            {
                toHome()
                backStackClosure?.invoke()
            }
        }
    }

    private fun toGame(uid: Int) {
        CoroutineScope(dispatcherProvider.default).launch {
            favsProvider.get().fold({ error ->
                _error.update { error }
            }) { favs ->
                _isFavorited.update { favs.any { it.uid == uid } }
                _canFavorite.update { true }
                gameProvider.get(ArrayList<Int>().apply { add(uid) }).collect {
                    it.fold({ error ->
                        _error.update { error }
                    }) { game ->
                        _title.update { game[0].name }
                    }
                }
            }
        }
        _canNavigateBack.update { true }
        _canFavorite.update { true }
        _navClicked.update {
            {
                toHome()
                backStackClosure?.invoke()
            }
        }
    }

    fun toChar(charUid: Int, gameUid: Int) {
        CoroutineScope(dispatcherProvider.default).launch {
            favsProvider.get().fold({ error -> _error.update { error } }) { favs ->
                _isFavorited.update { favs.any { it.uid == charUid } }
                _canFavorite.update { true }
            }
            charProvider.get(ArrayList<Int>().apply { add(charUid) }).collect {
                it.fold({ error -> _error.update { error } }) { chars ->
                    _title.update { chars[0].name }
                }
            }
        }
        _canNavigateBack.update { true }
        _canFavorite.update { true }
        _navClicked.update {
            {
                toGame(gameUid)
                backStackClosure?.invoke()
            }
        }
    }

    companion object {
        private const val DEFAULT_TITLE = "KOFERO"
    }
}
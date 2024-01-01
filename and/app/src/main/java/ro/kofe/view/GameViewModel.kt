package ro.kofe.view

import android.util.Log
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.game.GameInteractor
import ro.kofe.presenter.ipv.game.GameKView
import javax.inject.Inject

@HiltViewModel
class GameViewModel @Inject constructor(private val interactor: GameInteractor) : GameKView,
    ImageViewModel(interactor) {
    init {
        interactor.setView(this)
    }

    private val _chars = MutableStateFlow<List<Character>>(ArrayList())
    val chars = _chars.asStateFlow()

    private val _game = MutableStateFlow<Game?>(null)
    val game = _game.asStateFlow()

    private val _charError = MutableStateFlow<Error?>(null)
    val charError = _charError.asStateFlow()

    private val _gameError = MutableStateFlow<Error?>(null)
    val gameError = _gameError.asStateFlow()

    override fun display(characters: List<Character>) = _chars.update {
        Log.v("rwr", "display Chars: $characters")
        characters
    }

    override fun display(game: Game) = _game.update {
        Log.v("rwr", "display game $game")
        game
    }

    override fun displayCharsError(error: Error) = _charError.update {
        Log.v("rwr", "display chars error $error")
        error
    }

    override fun displayGameError(error: Error) = _gameError.update {
        Log.v("rwr", "display game error $error")
        error
    }

    override fun error(e: Exception) = super.error(e)

    fun charPressed(char: Character) = CoroutineScope(DispatcherProvider.default).launch {
        Log.v("rwr", "CHAR PRESSED: $char")
        interactor.charPressed(char)
    }

    fun setGameUid(uid: Int) = CoroutineScope(DispatcherProvider.default).launch {
        Log.v("rwr", "setGameUid: $uid")
        interactor.setGameUid(uid)
    }

}
package ro.kofe.view

import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
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
        characters
    }

    override fun display(game: Game) = _game.update {
        game
    }

    override fun displayCharsError(error: Error) = _charError.update {
        error
    }

    override fun displayGameError(error: Error) = _gameError.update {
        error
    }

    override fun error(e: Exception) = super.error(e)
}
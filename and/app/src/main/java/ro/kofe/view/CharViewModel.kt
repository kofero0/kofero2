package ro.kofe.view

import androidx.lifecycle.ViewModel
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterKView
import javax.inject.Inject

@HiltViewModel
class CharViewModel @Inject constructor(
    private val interactor:CharacterInteractor
): CharacterKView, ImageViewModel(interactor) {
    init {
        interactor.setView(this)
    }

    private val _moves = MutableStateFlow<List<Move>>(ArrayList())
    val moves = _moves.asStateFlow()

    private val _char = MutableStateFlow<Character?>(null)
    val char = _char.asStateFlow()

    private val _charError = MutableStateFlow<Error?>(null)
    val charError = _charError.asStateFlow()

    private val _moveError = MutableStateFlow<Error?>(null)
    val gameError = _moveError.asStateFlow()

    override fun display(moves: List<Move>) = _moves.update {
        moves
    }

    override fun display(character: Character) = _char.update {
        character
    }

    override fun displayMovesError(error: Error) = _moveError.update {
        error
    }
}
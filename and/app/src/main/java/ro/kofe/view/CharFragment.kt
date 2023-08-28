package ro.kofe.view

import androidx.fragment.app.Fragment
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Move
import ro.kofe.presenter.ipv.character.CharacterInteractor
import ro.kofe.presenter.ipv.character.CharacterKView

class CharFragment(private val interactor: CharacterInteractor): CharacterKView, Fragment() {
    override fun display(url: String, imgBase64: String) {
        TODO("Not yet implemented")
    }

    override fun display(moves: List<Move>) {
        TODO("Not yet implemented")
    }

    override fun display(character: Character) {
        TODO("Not yet implemented")
    }

    override fun displayMovesError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }
}
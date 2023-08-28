package ro.kofe.view

import androidx.fragment.app.Fragment
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.game.GameInteractor
import ro.kofe.presenter.ipv.game.GameKView

class GameFragment(private val interactor:GameInteractor): GameKView, Fragment() {

    init{
        interactor.setView(this)
    }

    override fun display(url: String, imgBase64: String) {
        TODO("Not yet implemented")
    }

    override fun display(characters: List<Character>) {
        TODO("Not yet implemented")
    }

    override fun display(game: Game) {
        TODO("Not yet implemented")
    }

    override fun displayCharsError(error: Error) {
        TODO("Not yet implemented")
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }
}
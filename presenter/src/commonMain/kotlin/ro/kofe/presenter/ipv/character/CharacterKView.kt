package ro.kofe.presenter.ipv.character

import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Move
import ro.kofe.presenter.ipv.ImageKView

interface CharacterKView : ImageKView {
    fun display(character: Character)
    fun display(moves: List<Move>)
    fun displayMovesError(error: Error)
    fun displayCharError(error: Error)
}
package ro.kofe.presenter.ipv.character

import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Move
import ro.kofe.presenter.ipv.KView

interface CharacterKView : KView {
    fun display(character: Character)
    fun display(moves: List<Move>)
    fun display(url: String, imgBase64: String)
    fun displayMovesError(error: Error)
}
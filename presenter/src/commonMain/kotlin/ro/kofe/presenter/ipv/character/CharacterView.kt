package ro.kofe.presenter.ipv.character

import ro.kofe.model.Character
import ro.kofe.model.Move
import ro.kofe.presenter.ipv.View

interface CharacterView : View {
    fun display(character: Character)
    fun display(moves: List<Move>)
    fun display(url: String, imgBase64: String)
    fun displayNotOnDisk(url: String)
}
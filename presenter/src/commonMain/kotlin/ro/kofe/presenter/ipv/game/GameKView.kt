package ro.kofe.presenter.ipv.game

import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.KView

interface GameKView : KView {
    fun display(game: Game)
    fun display(characters: List<Character>)
    fun display(url: String, imgBase64: String)
    fun displayCharsError(error: Error)
}
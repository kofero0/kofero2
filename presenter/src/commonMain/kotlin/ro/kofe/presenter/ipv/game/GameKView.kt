package ro.kofe.presenter.ipv.game

import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.ImageKView
import ro.kofe.presenter.ipv.KView

interface GameKView : ImageKView {
    fun display(game: Game)
    fun display(characters: List<Character>)
    fun displayCharsError(error: Error)
    fun displayGameError(error: Error)
}
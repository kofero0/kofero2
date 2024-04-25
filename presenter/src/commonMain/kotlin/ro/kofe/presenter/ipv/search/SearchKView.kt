package ro.kofe.presenter.ipv.search

import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.presenter.ipv.ImageKView
import ro.kofe.presenter.ipv.KView

interface SearchKView: ImageKView {
    fun showGames(games: List<Game>)
    fun showChars(chars: List<Character>)
}
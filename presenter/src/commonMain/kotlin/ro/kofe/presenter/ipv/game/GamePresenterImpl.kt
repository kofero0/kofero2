package ro.kofe.presenter.ipv.game

import arrow.core.Either
import arrow.core.raise.either
import ro.kofe.model.Character
import ro.kofe.model.Error
import ro.kofe.model.Game
import ro.kofe.model.IncorrectCount
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.Provider

class GamePresenterImpl(
    private var characterProvider: Provider<Character>,
    private var gameProvider: Provider<Game>,
    private var imageProvider: ImageProvider
) : GamePresenter {
    private var view: GameView? = null

    override fun setView(view: GameView) {
        this.view = view
    }

    override suspend fun showGame(id: Int): Either<Error, Unit> = either {
        val ids = ArrayList<Int>().apply { add(id) }
        gameProvider.get(ids).map { games ->
            if (games.size != 1) {
                raise(IncorrectCount(ids))
            }
            val game = games[0]
            view?.display(game)
            imageProvider.get(game.iconUrl).map { img -> view?.display(game.iconUrl, img.image) }
            characterProvider.get(game.charIds).map { chars -> view?.display(chars) }
        }
    }

    override fun shutdown() {
        view = null
    }
}
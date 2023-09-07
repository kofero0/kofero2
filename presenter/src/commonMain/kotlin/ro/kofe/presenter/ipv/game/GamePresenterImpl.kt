package ro.kofe.presenter.ipv.game

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.IncorrectCount
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.Provider

class GamePresenterImpl(
    private var characterProvider: Provider<Character>,
    private var gameProvider: Provider<Game>,
    private var imageProvider: ImageProvider
) : GamePresenter {
    private var view: GameKView? = null

    override fun setView(view: GameKView) {
        this.view = view
    }

    override suspend fun showGame(id: Int) = flow {
        val ids = ArrayList<Int>().apply { add(id) }
        suspend fun process(games: List<Game>) {
            if (games.size != 1) {
                emit(IncorrectCount(ids))
                return
            }
            val game = games[0]
            view?.display(game)
            imageProvider.get(game.iconUrl).fold({ emit(it) }) { view?.display(game.iconUrl, it) }
            characterProvider.get(game.charIds).collect { either ->
                either.fold({ e ->
                    emit(e)
                    view?.displayCharsError(e)
                }) { chars ->
                    view?.display(chars)
                }
            }
        }

        gameProvider.get(ids).collect { either ->
            either.fold({ e ->
                emit(e)
                view?.displayGameError(e)
            }) { process(it) }
        }
    }

    override fun shutdown() {
        view = null
    }
}
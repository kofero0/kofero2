package ro.kofe.presenter.ipv.game

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.IncorrectCount
import ro.kofe.model.logging.Level
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider

class GamePresenterImpl(
    private val characterProvider: Provider<Character>,
    private val gameProvider: Provider<Game>,
    private val imageProvider: ImageProvider,
    private val loggingProvider: LoggingProvider
) : GamePresenter {
    private var view: GameKView? = null

    override fun setView(view: GameKView) {
        this.view = view
    }

    override suspend fun showGame(id: Int) = flow {
        loggingProvider.log(Level.DEBUG, "GamePresenterImpl", "showGame: $id")
        val ids = ArrayList<Int>().apply { add(id) }
        suspend fun process(games: List<Game>) {
            if (games.size != 1) {
                emit(IncorrectCount(ids))
                return
            }
            val game = games[0]
            loggingProvider.log(Level.DEBUG, "GamePresenterImpl", "chars: ${game.charIds}")
            view?.display(game)
            imageProvider.get(game.iconUrl).fold({ emit(it) }) { view?.display(game.iconUrl, it) }
            characterProvider.get(game.charIds).collect { either ->
                either.fold({ e ->
                    emit(e)
                    view?.displayCharsError(e)
                }) { chars ->
                    for (char in chars) {
                        imageProvider.get(char.iconUrl)
                            .fold({ emit(it) }) { view?.display(char.iconUrl, it) }
                    }
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
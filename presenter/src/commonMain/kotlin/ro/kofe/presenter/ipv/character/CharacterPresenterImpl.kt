package ro.kofe.presenter.ipv.character

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.IncorrectCount
import ro.kofe.model.Move
import ro.kofe.model.logging.Level
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider

class CharacterPresenterImpl(
    private val charProvider: Provider<Character>,
    private val moveProvider: Provider<Move>,
    private val imageProvider: ImageProvider
) : CharacterPresenter {
    private var view: CharacterKView? = null

    override fun setView(view: CharacterKView) {
        this.view = view
    }

    override suspend fun showChar(id: Int) = flow {
        val ids = ArrayList<Int>().apply { add(id) }
        suspend fun process(chars: List<Character>) {
            if (chars.size != 1) {
                emit(IncorrectCount(ids))
            }
            val char = chars[0]
            view?.display(char)
            imageProvider.get(char.iconUrl).fold({ emit(it) }) { view?.display(char.iconUrl, it) }
            moveProvider.get(char.moveIds).collect { either ->
                either.fold({
                    emit(it)
                    view?.displayMovesError(it)
                }) { moves ->
                    view?.display(moves)
                }
            }
        }

        charProvider.get(ids).collect { either ->
            either.fold({
                emit(it)
                view?.displayCharError(it)
            }) { process(it) }
        }
    }

    override fun shutdown() {
        view = null
    }
}
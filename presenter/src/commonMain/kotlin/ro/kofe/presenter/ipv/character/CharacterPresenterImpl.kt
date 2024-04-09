package ro.kofe.presenter.ipv.character

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.IncorrectCount
import ro.kofe.model.Move
import ro.kofe.presenter.provider.ImageProvider
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

    override suspend fun showChar(charUid: Int, gameUid:Int) = flow {
        val ids = ArrayList<Int>().apply { add(charUid) }
        suspend fun process(chars: List<Character>) {
            if (chars.size != 1) {
                emit(IncorrectCount(ids))
            }
            val char = chars.first()
            view?.display(char)
            imageProvider.get(char.iconUrl).fold({ emit(it) }) { view?.display(char.iconUrl, it) }
            moveProvider.get(char.moveIds).collect { either ->
                either.fold({
                    emit(it)
                    view?.displayMovesError(it)
                }) { moves ->
                    view?.display(moves, gameUid)
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
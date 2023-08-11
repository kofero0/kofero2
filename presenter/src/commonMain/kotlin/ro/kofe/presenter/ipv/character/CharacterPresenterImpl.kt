package ro.kofe.presenter.ipv.character

import arrow.core.Either
import arrow.core.raise.either
import arrow.core.raise.ensure
import ro.kofe.model.Character
import ro.kofe.model.IncorrectCount
import ro.kofe.model.Move
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.Provider

class CharacterPresenterImpl(
    private val charProvider: Provider<Character>,
    private val moveProvider: Provider<Move>,
    private val imageProvider: ImageProvider
) : CharacterPresenter {
    private var view: CharacterView? = null

    override fun setView(view: CharacterView) {
        this.view = view
    }

    override suspend fun showChar(id: Int) = either {
        val ids = ArrayList<Int>().apply { add(id) }
        charProvider.get(ids).map { chars ->
            ensure(chars.size == 1) { raise(IncorrectCount(ids)) }
            view?.display(chars[0])
            imageProvider.get(chars[0].iconUrl).map { image ->
                view?.display(chars[0].iconUrl, image.image)
            }
            moveProvider.get(chars[0].moveIds).map { moves ->
                view?.display(moves)
            }
        }
        Unit
    }

    override fun shutdown() {
        view = null
    }
}
package ro.kofe.presenter.ipv.character

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch
import ro.kofe.model.logging.LogTag.CHARACTER_INTERACTOR
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import kotlin.coroutines.CoroutineContext

class CharacterInteractorImpl(
    presenter: CharacterPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider,
    private val context: CoroutineContext
) : InteractorImpl<CharacterKView, CharacterPresenter>(
    presenter, stateLogger, stateReducer, loggingProvider, CHARACTER_INTERACTOR
), CharacterInteractor {

    private var charUid: Int? = null
    private var gameUid: Int? = null

    override suspend fun setUids(charUid: Int, gameUid: Int) {
        this.charUid = charUid
        this.gameUid = gameUid
    }

    override fun shutdown() {
        charUid = null
        view = null
    }

    override fun viewResumed() = super.viewResumed().also {
        CoroutineScope(context).launch {
            gameUid?.let { gUid ->
                charUid?.let { presenter.showChar(it, gUid).collect { error -> view?.displayCharError(error) } }
            }
        }
    }
}
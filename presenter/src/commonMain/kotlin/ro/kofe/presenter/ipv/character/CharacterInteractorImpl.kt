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
    router: CharacterRouter,
    private val context: CoroutineContext
) : InteractorImpl<CharacterKView, CharacterPresenter>(
    presenter, stateLogger, stateReducer, router, loggingProvider, CHARACTER_INTERACTOR
), CharacterInteractor {

    private var charUid: Int? = null

    override fun setCharUid(uid: Int) {
        charUid = uid
    }

    override fun setView(view: CharacterKView) {
        this.view = view
    }

    override fun shutdown() {
        charUid = null
        view = null
    }

    override fun viewResumed() = super.viewResumed().also {
        CoroutineScope(context).launch {
            charUid?.let { presenter.showChar(it) }
        }
    }
}
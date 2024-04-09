package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.DelicateCoroutinesApi
import kotlinx.coroutines.launch
import ro.kofe.model.HttpError
import ro.kofe.model.logging.Level
import ro.kofe.model.logging.LogTag.ROOT_INTERACTOR
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

@OptIn(DelicateCoroutinesApi::class)
class RootInteractorImpl(
    presenter: RootPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider,
    private val dispatcherProvider: DispatcherProvider
) : InteractorImpl<RootKView, RootPresenter>(
    presenter,
    stateLogger,
    stateReducer,
    loggingProvider,
    ROOT_INTERACTOR
), RootInteractor {

    override fun setView(view: RootKView) {
        this.view = view
    }

    override fun shutdown() {
        view = null
    }

    override fun viewPaused() {
    }

    override fun viewResumed() = super.viewResumed().also {
        CoroutineScope(dispatcherProvider.default).launch {
            try{
                presenter.checkVersion().collect {
                    log(Level.ALERT, "provider error checking version! $it")
                    if (it is HttpError) {
                        log(Level.ALERT, "code: ${it.statusCode} body: ${it.response}")
                    }
                }
            } catch (e: Exception) {
                view?.error(e)
                log(Level.ALERT, "connectException?: ${e.printStackTrace()}")
            }
        }
    }
}
package ro.kofe.presenter.ipv.acknowledgment

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.DelicateCoroutinesApi
import kotlinx.coroutines.launch
import ro.kofe.model.HttpError
import ro.kofe.model.logging.Level
import ro.kofe.model.logging.LogTag.ACK_INTERACTOR
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.ipv.Interactor
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer

interface AckInteractor: Interactor<AckKView>

@OptIn(DelicateCoroutinesApi::class)
class AckInteractorImpl(
    presenter: AckPresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider,
    private val dispatcherProvider:DispatcherProvider
): AckInteractor, InteractorImpl<AckKView,AckPresenter>(
    presenter,
    stateLogger,
    stateReducer,
    loggingProvider,
    ACK_INTERACTOR
) {
    override fun viewResumed() = super.viewResumed().also {
        CoroutineScope(dispatcherProvider.default).launch {
            presenter.showAck().collect { error ->
                log(Level.ALERT, "provider error checking version! $error")
                if (error is HttpError) {
                    log(Level.ALERT, "code: ${error.statusCode} body: ${error.response}")
                }
            }
        }
    }
}
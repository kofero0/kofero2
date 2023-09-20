package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Status
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.StatusProvider

class RootPresenterImpl(private val statusProvider: StatusProvider, loggingProvider: LoggingProvider) :
    RootPresenter, PresenterImpl<RootKView>(null, loggingProvider, ROOT_PRESENTER) {

    override suspend fun checkVersion() = flow {
        fun split(status: Status) = status.version.split(".")
        statusProvider.getBackendStatus().fold({ emit(it) }) { status ->
            val local = split(statusProvider.getLocalStatus())
            val backend = split(status)
            if(backend[0] > local[0]) { view?.promptUpdate() }
            else {
                if(backend[1] > local[1]) { view?.promptUpdate() }
                else {
                    if(backend[2] > local[2]) { view?.promptUpdate() }
                }
            }
        }
    }

    override fun setView(view: RootKView) {
        this.view = view
    }

    override fun shutdown() {
        view = null
    }
}
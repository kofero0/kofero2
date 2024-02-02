package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.flow.flow
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.StatusProvider

class RootPresenterImpl(private val statusProvider: StatusProvider, loggingProvider: LoggingProvider) :
    RootPresenter, PresenterImpl<RootKView>(null, loggingProvider, ROOT_PRESENTER) {

    override suspend fun checkVersion() = flow {
        statusProvider.getBackendStatus().fold({ emit(it) }) { status ->
            val local = statusProvider.getLocalStatus().version.split(".")
            val backend = status.version.split(".")
            if(local.size == backend.size) {
                for (element in backend) {
                    if (element > local[backend.indexOf(element)]) {
                        view?.promptUpdate()
                    }
                }
            } else{
                view?.error(Exception("Unequal version strings"))
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
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
            run breaking@ {
                for(loc in local){
                    if(backend[local.indexOf(loc)].toInt() > loc.toInt()){
                        view?.promptUpdate()
                        return@breaking
                    }
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
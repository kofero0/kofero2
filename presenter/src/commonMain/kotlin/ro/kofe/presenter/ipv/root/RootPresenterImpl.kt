package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.AuthProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider
import ro.kofe.presenter.provider.StatusProvider

class RootPresenterImpl(
    private val statusProvider: StatusProvider,
    private val authProvider: AuthProvider,
    private val gameProvider: Provider<Game>,
    private val charProvider: Provider<Character>,
    private val moveProvider: Provider<Move>,
    loggingProvider: LoggingProvider
) : RootPresenter, PresenterImpl<RootKView>(null, loggingProvider, ROOT_PRESENTER) {

    override suspend fun checkVersion() = flow {
        statusProvider.getBackendStatus().fold({ emit(it) }) { status ->
            val local = statusProvider.getLocalStatus().version.split(".")
            val backend = status.version.split(".")
            if (local.size == backend.size) {
                for (element in backend) {
                    if (element > local[backend.indexOf(element)]) {
                        view?.promptUpdate()
                        authProvider.delete()
                        gameProvider.delete()
                        charProvider.delete()
                        moveProvider.delete()
                    }
                }
            } else {
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
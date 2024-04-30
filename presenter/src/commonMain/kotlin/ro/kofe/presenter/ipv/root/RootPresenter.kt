package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter
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

interface RootPresenter : Presenter<RootKView> {
    suspend fun checkVersion(): Flow<ProviderError>
}

class RootPresenterImpl(
    private val statusProvider: StatusProvider,
    private val authProvider: AuthProvider,
    private val gameProvider: Provider<Game>,
    private val charProvider: Provider<Character>,
    private val moveProvider: Provider<Move>,
    loggingProvider: LoggingProvider
) : RootPresenter, PresenterImpl<RootKView>(null, loggingProvider, ROOT_PRESENTER) {

    override suspend fun checkVersion(): Flow<ProviderError> {
        val local = statusProvider.getLocalStatus().version.split(".")
        return flow {
            statusProvider.getBackendStatus().fold({ emit(it) }) { status ->
                val backend = status.version.split(".")
                println("@@@local: $local")
                println("@@@backend: $backend")
                if (local.size == backend.size) {
                    for (element in backend) {
                        if (element > local[backend.indexOf(element)]) {
                            println("deleted")
                            view?.promptUpdate()
                            authProvider.delete()
                            gameProvider.delete()
                            charProvider.delete()
                            moveProvider.delete()
                            gameProvider.get(ArrayList()).collect {}
                        }
                    }
                } else {
                    view?.error(Exception("Unequal version strings"))
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
package ro.kofe.presenter.ipv.root

import ro.kofe.model.Game
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider

class RootPresenterImpl(private val gameProvider: Provider<Game>, loggingProvider: LoggingProvider) :
    RootPresenter, PresenterImpl<RootKView>(null, loggingProvider, ROOT_PRESENTER) {

    override fun setView(view: RootKView) {
        this.view = view
    }

    override fun shutdown() {
        view = null
    }
}
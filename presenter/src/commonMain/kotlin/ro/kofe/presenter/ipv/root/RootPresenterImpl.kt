package ro.kofe.presenter.ipv.root

import ro.kofe.model.Game
import ro.kofe.model.logging.LogTag.ROOT_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider

class RootPresenterImpl(private val gameProvider: Provider<Game>, loggingProvider: LoggingProvider) :
    RootPresenter, PresenterImpl<RootView>(null, loggingProvider, ROOT_PRESENTER) {

    override fun setView(view: RootView) {
        this.view = view
    }

    override fun shutdown() {
        view = null
    }
}
package ro.kofe.presenter.ipv

import ro.kofe.presenter.provider.LoggingProvider

interface Presenter<V : KView> {
    fun setView(view: V)
    fun shutdown()
}

abstract class PresenterImpl<V : KView>(
    internal var view: V? = null,
    loggingProvider: LoggingProvider?,
    logTag: String
) : KoferoObj(loggingProvider, logTag), Presenter<V> {

    override fun shutdown() {
        super.shutdown()
        view = null
    }

    override fun setView(view: V) {
        this.view = view
    }
}
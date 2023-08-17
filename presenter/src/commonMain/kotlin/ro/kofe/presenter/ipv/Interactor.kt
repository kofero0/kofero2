package ro.kofe.presenter.ipv

interface Interactor<V : KView> {
    fun setView(view: V)
    fun shutdown()
    fun viewPaused()
    fun viewResumed()
}
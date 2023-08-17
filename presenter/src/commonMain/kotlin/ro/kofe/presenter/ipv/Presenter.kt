package ro.kofe.presenter.ipv

interface Presenter<V : KView> {
    fun setView(view: V)
    fun shutdown()
}
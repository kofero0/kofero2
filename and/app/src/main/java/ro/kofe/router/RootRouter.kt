package ro.kofe.router

import ro.kofe.model.Event
import ro.kofe.presenter.ipv.root.RootRouter

class RootRouterImpl(
    private val 
): RootRouter  {
    override fun routeTo(view: Event.ViewTag, uid: Int): Boolean {
        TODO("Not yet implemented")
    }
}
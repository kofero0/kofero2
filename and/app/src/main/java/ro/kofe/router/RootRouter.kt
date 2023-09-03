package ro.kofe.router

import ro.kofe.model.Event
import ro.kofe.presenter.ipv.root.RootRouter

class RootRouterImpl : RootRouter {
    override fun routeTo(view: Event.ViewTag, uid: Int): Boolean {
        return true
    }
}
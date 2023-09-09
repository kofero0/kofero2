package ro.kofe.router

import ro.kofe.model.ViewTag
import ro.kofe.presenter.ipv.root.RootRouter

class RootRouterImpl : RootRouter {
    override fun routeTo(view: ViewTag, uid: Int) = true
}
package ro.kofe.router

import ro.kofe.model.ViewTag
import ro.kofe.presenter.ipv.home.HomeRouter

class HomeRouterImpl: HomeRouter {
    override fun routeTo(view: ViewTag, uid: Int) = true
}
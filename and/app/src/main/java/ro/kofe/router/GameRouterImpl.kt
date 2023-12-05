package ro.kofe.router

import ro.kofe.model.ViewTag
import ro.kofe.presenter.ipv.game.GameRouter

class GameRouterImpl : GameRouter {
    override fun routeTo(view: ViewTag, uid: Int) = true
}
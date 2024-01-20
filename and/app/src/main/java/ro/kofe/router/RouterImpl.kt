package ro.kofe.router

import ro.kofe.model.ViewTag
import ro.kofe.presenter.ipv.character.CharacterRouter
import ro.kofe.presenter.ipv.game.GameRouter
import ro.kofe.presenter.ipv.home.HomeRouter
import ro.kofe.presenter.ipv.root.RootRouter

class RouterImpl : GameRouter, CharacterRouter, HomeRouter, RootRouter {
    override fun routeTo(view: ViewTag, uid: Int) = true
}
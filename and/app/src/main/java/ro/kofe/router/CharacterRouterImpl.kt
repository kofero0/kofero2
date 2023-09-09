package ro.kofe.router

import ro.kofe.model.ViewTag
import ro.kofe.presenter.ipv.character.CharacterRouter

class CharacterRouterImpl: CharacterRouter {
    override fun routeTo(view: ViewTag, uid: Int) = true
}
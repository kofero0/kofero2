package ro.kofe.presenter.ipv

import ro.kofe.model.ViewTag


interface Router {
    fun routeTo(view: ViewTag, uid: Int): Boolean
}
package ro.kofe.presenter.ipv

import ro.kofe.model.Event

interface Router {
    fun routeTo(view: Event.ViewTag, uid: Int): Boolean
}
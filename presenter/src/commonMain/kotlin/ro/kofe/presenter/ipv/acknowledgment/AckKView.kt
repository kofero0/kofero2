package ro.kofe.presenter.ipv.acknowledgment

import ro.kofe.presenter.ipv.KView

interface AckKView: KView {
    fun display(copy:String)
}
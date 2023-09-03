package ro.kofe.view

import ro.kofe.presenter.ipv.KView

interface ViewBuilder<T : KView> {
    fun build(): T
}
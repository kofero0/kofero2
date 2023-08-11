package ro.kofe.presenter.provider

import arrow.core.Ior
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError

interface Provider<T : Obj> {
    fun get(ids: List<Int>): Ior<ProviderError, List<T>>
}
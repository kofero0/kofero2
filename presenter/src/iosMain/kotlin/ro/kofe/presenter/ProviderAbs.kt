package ro.kofe.presenter

import arrow.core.Ior
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.Provider

abstract class ProviderAbs<R: Obj>:Provider<R> {
    abstract override suspend fun get(ids: List<Int>): Ior<ProviderError, List<R>>
    //objc protocols do not support generics
}
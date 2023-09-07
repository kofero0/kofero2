package ro.kofe.presenter.provider

import arrow.core.Either
import arrow.core.Ior
import kotlinx.coroutines.flow.Flow
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError
import ro.kofe.presenter.Cancellable
import ro.kofe.presenter.collect


interface Provider<T : Obj> {
    fun get(ids: List<Int>): Flow<Either<ProviderError, List<T>>>

    fun get(
        ids: List<Int>,
        onEach: (Either<ProviderError, List<T>>) -> Unit,
        onCompletion: (Throwable?) -> Unit
    ): Cancellable =
        get(ids).collect(onEach, onCompletion)
}
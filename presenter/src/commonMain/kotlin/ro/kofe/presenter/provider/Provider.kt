package ro.kofe.presenter.provider

import arrow.core.Either
import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.Cancellable
import ro.kofe.presenter.collect


interface Provider<T> {
    fun get(ids: List<Int>): Flow<Either<ProviderError, List<T>>>

    fun get(
        ids: List<Int>,
        onEach: (Either<ProviderError, List<T>>) -> Unit,
        onCompletion: (Throwable?) -> Unit
    ): Cancellable =
        get(ids).collect(onEach, onCompletion)

    fun search(query: List<String>): Flow<Either<ProviderError, List<T>>>

    fun search(query: List<String>,
               onEach: (Either<ProviderError, List<T>>) -> Unit,
               onCompletion: (Throwable?) -> Unit
               ): Cancellable =
        search(query).collect(onEach,onCompletion)

    fun delete(): Either<ProviderError,Unit>
}
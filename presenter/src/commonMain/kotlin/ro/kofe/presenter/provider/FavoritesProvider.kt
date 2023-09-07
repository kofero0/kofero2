package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError

interface FavoritesProvider : Provider<Obj> {
    suspend fun save(id: Int): Either<ProviderError, Unit>
    suspend fun delete(id: Int): Either<ProviderError, Unit>
}
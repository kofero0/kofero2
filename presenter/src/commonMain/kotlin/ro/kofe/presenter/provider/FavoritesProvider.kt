package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError

interface FavoritesProvider : Provider<Obj> {
    fun save(item: Obj) : Either<ProviderError, Unit>
    fun delete(item: Obj): Either<ProviderError, Unit>
}
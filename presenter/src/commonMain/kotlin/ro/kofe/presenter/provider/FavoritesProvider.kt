package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.Favorite
import ro.kofe.model.ProviderError

interface FavoritesProvider {
    suspend fun save(fav: Favorite): Either<ProviderError, Unit>
    suspend fun delete(id: Int): Either<ProviderError, Unit>
    suspend fun get(): Either<ProviderError, List<Favorite>>
}
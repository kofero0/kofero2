package ro.kofe.provider

import android.content.Context
import arrow.core.Either
import arrow.core.Ior
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.Provider

class FavoritesProviderImpl(private val context: Context): FavoritesProvider {
    override suspend fun delete(item: Obj): Either<ProviderError, Unit> {
        TODO("Not yet implemented")
    }

    override suspend fun get(ids: List<Int>): Ior<ProviderError, List<Obj>> {
        TODO("Not yet implemented")
    }

    override suspend fun save(item: Obj): Either<ProviderError, Unit> {
        TODO("Not yet implemented")
    }
}
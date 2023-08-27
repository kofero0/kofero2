package ro.kofe.provider

import android.content.Context
import arrow.core.Either
import arrow.core.Ior
import arrow.core.raise.either
import arrow.core.raise.ior
import ro.kofe.model.CombinedError
import ro.kofe.model.Obj
import ro.kofe.model.OtherError
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.Provider
import java.io.File

class FavoritesProviderImpl(private val context: Context): FavoritesProvider {
    private val file: File by lazy { File(context.filesDir,"fav").apply { if(!exists()) mkdir() } }

    override suspend fun delete(item: Obj) = either<ProviderError, Unit> {

    }

    override suspend fun get(ids: List<Int>) = ior<ProviderError, List<Obj>>({e1,e2 -> CombinedError(e1,e2)}) {
        raise(OtherError)
    }

    override suspend fun save(item: Obj) = either<ProviderError, Unit> {

    }
}
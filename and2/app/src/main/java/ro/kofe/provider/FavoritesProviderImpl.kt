package ro.kofe.provider

import android.content.Context
import arrow.core.Either
import arrow.core.Ior
import arrow.core.raise.either
import arrow.core.raise.ior
import kotlinx.coroutines.flow.Flow
import ro.kofe.model.CombinedError
import ro.kofe.model.Obj
import ro.kofe.model.OtherError
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.FavoritesProvider
import java.io.File

class FavoritesProviderImpl(private val context: Context) : FavoritesProvider {
    private val file: File by lazy {
        File(
            context.filesDir,
            "fav"
        ).apply { if (!exists())
            createNewFile()
            writeBytes("[]".toByteArray())
        }
    }

    override suspend fun delete(id: Int): Either<ProviderError, Unit> {
        TODO("Not yet implemented")
    }

    override fun get(ids: List<Int>): Flow<Either<ProviderError, List<Obj>>> {
        TODO("Not yet implemented")
    }

    override suspend fun save(id: Int): Either<ProviderError, Unit> {
        TODO("Not yet implemented")
    }


}
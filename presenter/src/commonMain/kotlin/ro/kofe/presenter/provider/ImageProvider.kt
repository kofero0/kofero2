package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError

interface ImageProvider {
    suspend fun get(url: String): Either<ProviderError, String>
}
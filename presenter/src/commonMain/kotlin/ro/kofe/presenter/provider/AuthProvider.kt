package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError


interface AuthProvider {
    suspend fun get(): Either<ProviderError, String>
}
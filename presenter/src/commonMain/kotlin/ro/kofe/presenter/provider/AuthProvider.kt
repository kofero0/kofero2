package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError


interface AuthProvider {
    fun get(): Either<ProviderError, String>
    fun delete(): Either<ProviderError, Unit>
}
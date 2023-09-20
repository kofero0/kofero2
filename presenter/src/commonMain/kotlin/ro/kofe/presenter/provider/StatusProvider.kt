package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError
import ro.kofe.model.Status

interface StatusProvider {
    suspend fun getBackendStatus(): Either<ProviderError, Status>
    suspend fun getLocalStatus(): Status
}
package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.Copy
import ro.kofe.model.ProviderError

interface CopyProvider {
   suspend fun get(): Either<ProviderError, Copy>
   fun delete(): Either<ProviderError, Unit>
}
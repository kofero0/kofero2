package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError

interface ImageProvider {
    fun get(url: String) : Either<ProviderError, String>
}
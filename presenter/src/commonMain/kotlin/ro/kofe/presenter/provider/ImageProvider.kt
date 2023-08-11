package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError
import ro.kofe.model.value.Base64Image

interface ImageProvider {
    fun get(url: String) : Either<ProviderError, Base64Image>
}
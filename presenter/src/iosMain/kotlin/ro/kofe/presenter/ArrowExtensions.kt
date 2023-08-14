package ro.kofe.presenter

import arrow.core.Either
import arrow.core.Ior
import arrow.core.left
import ro.kofe.model.ProviderError

object ArrowExtensions {

    fun buildImageEitherLeft(left: ProviderError): Either<ProviderError,String> = Either.Left(left)

    fun buildImageEitherRight(right: String): Either<ProviderError, String> = Either.Right(right)

}
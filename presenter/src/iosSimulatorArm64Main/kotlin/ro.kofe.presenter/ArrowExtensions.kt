package ro.kofe.presenter

import arrow.core.Either
import arrow.core.Ior
import platform.Foundation.NSArray
import platform.Foundation.NSDictionary
import ro.kofe.model.ProviderError
import ro.kofe.model.Status

object ArrowExtensions {

    fun buildStatusEitherLeft(left: ProviderError): Either<ProviderError,Status> = Either.Left(left)

    fun buildStatusEitherRight(right: Status): Either<ProviderError,Status> = Either.Right(right)

    fun buildImageEitherLeft(left: ProviderError): Either<ProviderError, String> = Either.Left(left)

    fun buildImageEitherRight(right: String): Either<ProviderError, String> = Either.Right(right)

    fun buildListIorLeft(left: ProviderError): Ior<ProviderError, NSArray> = Ior.Left(left)

    fun buildListIorRight(right: NSArray): Ior<ProviderError, NSArray> = Ior.Right(right)

    fun buildListIorBoth(left: ProviderError, right: NSArray): Ior<ProviderError, NSArray> = Ior.Both(left, right)

    fun buildListEitherLeft(left: ProviderError): Either<ProviderError, NSArray> = Either.Left(left)

    fun buildListEitherRight(right: NSArray): Either<ProviderError, NSArray> = Either.Right(right)

    fun buildUnitEitherLeft(left: ProviderError): Either<ProviderError, Unit> = Either.Left(left)

    fun buildUnitEitherRight(): Either<ProviderError, Unit> = Either.Right(Unit)

    fun buildNSDictionaryEitherLeft(error: ProviderError): Either<ProviderError, NSDictionary> = Either.Left(error)

    fun buildNSDictionaryEitherRight(dict: NSDictionary): Either<ProviderError, NSDictionary> = Either.Right(dict)
}
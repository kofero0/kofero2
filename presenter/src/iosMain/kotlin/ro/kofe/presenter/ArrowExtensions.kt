package ro.kofe.presenter

import arrow.core.Either
import arrow.core.Ior
import arrow.core.left
import platform.Foundation.NSArray
import platform.Foundation.NSDictionary
import ro.kofe.model.ProviderError

object ArrowExtensions {

    fun buildImageEitherLeft(left: ProviderError): Either<ProviderError,String> = Either.Left(left)

    fun buildImageEitherRight(right: String): Either<ProviderError, String> = Either.Right(right)

    fun buildListIorLeft(left: ProviderError): Ior<ProviderError,NSArray> = Ior.Left(left)

    fun buildListIorRight(right: NSArray): Ior<ProviderError, NSArray> = Ior.Right(right)

    fun buildListIorBoth(left: ProviderError, right: NSArray): Ior<ProviderError, NSArray> = Ior.Both(left,right)

    fun buildUnitEitherLeft(left: ProviderError): Either<ProviderError,Unit> = Either.Left(left)

    fun buildUnitEitherRight(): Either<ProviderError,Unit> = Either.Right(Unit)

    fun buildNSDictionaryEitherLeft(error:ProviderError): Either<ProviderError,NSDictionary> = Either.Left(error)

    fun buildNSDictionaryEitherRight(dict:NSDictionary): Either<ProviderError, NSDictionary> = Either.Right(dict)
}
package ro.kofe.presenter

import arrow.core.Either
import arrow.core.Ior

fun <Left, Right> buildEitherLeft(left: Left): Either<Left, Right> = Either.Left(left)

fun <Left, Right> buildEitherRight(right: Right): Either<Left, Right> = Either.Right(right)

fun <Left, Right> buildIorLeft(left: Left): Ior<Left, Right> = Ior.Left(left)

fun <Left, Right> buildIorRight(right: Right): Ior<Left, Right> = Ior.Right(right)

fun <Left, Right> buildIorBoth(left: Left, right: Right): Ior<Left, Right> = Ior.Both(left, right)
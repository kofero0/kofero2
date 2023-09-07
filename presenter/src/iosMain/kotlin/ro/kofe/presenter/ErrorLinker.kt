package ro.kofe.presenter

import ro.kofe.model.*


object ErrorLinker {
    val ids = IdsNotFound(ArrayList())
    val incorrectCount = IncorrectCount(ArrayList())
    val invalid = InvalidObject(5)
    val fileRead = FileReadError("")
    val noPerm = NoPermissionError
    val other = OtherError
    val http = HttpError(0, "")
}
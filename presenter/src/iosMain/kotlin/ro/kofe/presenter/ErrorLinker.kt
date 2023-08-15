package ro.kofe.presenter

import ro.kofe.model.FileReadError
import ro.kofe.model.NoPermission
import ro.kofe.model.Other

object ErrorLinker {
    val fileRead = FileReadError("")
    val noPerm = NoPermission
    val other = Other
    
}
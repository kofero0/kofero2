package ro.kofe.web

import java.security.MessageDigest
import java.security.SecureRandom

const val GAME_PATH = "/game"
const val CHAR_PATH = "/path"
const val MOVE_PATH = "/move"
const val STATUS_PATH = "/status"

fun getHash(password: String, salt: ByteArray?) = StringBuilder().apply {
    val bytes: ByteArray = MessageDigest.getInstance("SHA-256").apply {
        update(salt)
    }.digest(password.toByteArray())
    for (i in bytes.indices) {
        append(((bytes[i].toInt() and 0xff) + 0x100).toString(16).substring(1))
    }
}.toString()
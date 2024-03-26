package ro.kofe.web

import java.security.MessageDigest
import javax.servlet.http.HttpServletRequest

const val GAME_PATH = "/game"
const val CHAR_PATH = "/char"
const val MOVE_PATH = "/move"
const val COPY_PATH = "/copy"
const val STATUS_PATH = "/status"
const val PRIVACY_PATH = "/privacy"

fun String.getHash(salt: ByteArray?) = StringBuilder().apply {
    val bytes: ByteArray = MessageDigest.getInstance("SHA-256").apply {
        update(salt)
    }.digest(toByteArray())
    for (i in bytes.indices) {
        append(((bytes[i].toInt() and 0xff) + 0x100).toString(16).substring(1))
    }
}.toString()

fun HttpServletRequest.getURL(): String {
    val scheme = scheme // http
    val serverName = serverName // hostname.com
    val serverPort = serverPort // 80
    val contextPath = contextPath // /mywebapp
    val servletPath = servletPath // /servlet/MyServlet
    val pathInfo = pathInfo // /a/b;c=123
    val queryString = queryString // d=789

    // Reconstruct original requesting URL
    val url = StringBuilder()
    url.append(scheme).append("://").append(serverName)
    if (serverPort != 80 && serverPort != 443) {
        url.append(":").append(serverPort)
    }
    url.append(contextPath).append(servletPath)
    if (pathInfo != null) {
        url.append(pathInfo)
    }
    if (queryString != null) {
        url.append("?").append(queryString)
    }
    return url.toString()
}
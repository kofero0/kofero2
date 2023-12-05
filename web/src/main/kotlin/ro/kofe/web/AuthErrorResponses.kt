package ro.kofe.web

import org.springframework.http.HttpStatus
import ro.kofe.model.response.ErrorBody

object AuthErrorResponses {
    val MISSING_TOKEN = ErrorBody(HttpStatus.UNAUTHORIZED.value(), "missing auth token")
    val MALFORMED_AUTH_TOKEN = ErrorBody(HttpStatus.UNAUTHORIZED.value(), "malformed auth token")
    val AUTH_FAILED = ErrorBody(HttpStatus.UNAUTHORIZED.value(), "auth token hash failed")
}
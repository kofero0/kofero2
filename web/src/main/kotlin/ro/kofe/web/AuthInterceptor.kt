package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.http.HttpStatus
import org.springframework.stereotype.Component
import org.springframework.web.servlet.HandlerInterceptor
import ro.kofe.model.authDelimiter
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse


@Component
class AuthInterceptor(
    private val accountQueryService: AccountQueryService,
) : HandlerInterceptor {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }

    override fun preHandle(request: HttpServletRequest, response: HttpServletResponse, handler: Any): Boolean {
        val headerKey = "authorization"
        if (!request.headerNames.toList().contains(headerKey)) {
            response.writer.write(
                mapper.writeValueAsString(
                    AuthErrorResponses.MISSING_TOKEN
                )
            )
            response.status = HttpStatus.UNAUTHORIZED.value()
            return false
        }
        val authToken = request.getHeader(headerKey).split(authDelimiter)
        if (authToken.size != 2) {
            response.writer.write(
                mapper.writeValueAsString(
                    AuthErrorResponses.MALFORMED_AUTH_TOKEN
                )
            )
            response.status = HttpStatus.UNAUTHORIZED.value()
            return false
        }
        val account = accountQueryService.getAccountById(authToken[0].toLong())
        if(account == null) {
            response.writer.write(mapper.writeValueAsString(AuthErrorResponses.AUTH_FAILED))
            response.status = HttpStatus.UNAUTHORIZED.value()
            return false
        }
        val newHash = authToken[1].getHash(account.salt)
        println("ACCOUNT HASH: ${account.hash}")
        println("NEW HASH: $newHash")
        if (newHash != account.hash) {
            response.writer.write(
                mapper.writeValueAsString(
                    AuthErrorResponses.AUTH_FAILED
                )
            )
            response.status = HttpStatus.UNAUTHORIZED.value()
        }
        return newHash == account.hash
    }
}
package ro.kofe.web

import org.springframework.beans.factory.annotation.Autowired
import org.springframework.context.annotation.Configuration
import org.springframework.stereotype.Component
import org.springframework.stereotype.Service
import org.springframework.web.servlet.HandlerInterceptor
import org.springframework.web.servlet.ModelAndView
import org.springframework.web.servlet.config.annotation.InterceptorRegistry
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer
import ro.kofe.model.authDelimiter
import java.security.MessageDigest
import java.security.SecureRandom
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse


@Configuration
class WebConfig(
    @Autowired
    private val accountQueryService: AccountQueryService
) : WebMvcConfigurer {

    override fun addInterceptors(registry: InterceptorRegistry) {
        registry.addInterceptor(RequestInterceptor(accountQueryService))
            .addPathPatterns(ArrayList<String>().apply {
                add(GAME_PATH)
                add(CHAR_PATH)
                add(MOVE_PATH)
                add(STATUS_PATH)
            })
    }
}

fun getURL(req: HttpServletRequest): String {
    val scheme = req.scheme // http
    val serverName = req.serverName // hostname.com
    val serverPort = req.serverPort // 80
    val contextPath = req.contextPath // /mywebapp
    val servletPath = req.servletPath // /servlet/MyServlet
    val pathInfo = req.pathInfo // /a/b;c=123
    val queryString = req.queryString // d=789

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


@Component
class RequestInterceptor(
    private val accountQueryService: AccountQueryService,
) : HandlerInterceptor {

    override fun preHandle(request: HttpServletRequest, response: HttpServletResponse, handler: Any): Boolean {
        val authToken = request.getHeader("Authorization").split(authDelimiter)
        if (authToken.size != 2) {
            return false
        }
        val account = accountQueryService.getAccountById(authToken[0].toLong())
        val newHash = getHash(authToken[1], account?.salt)
        println("ACCOUNT HASH: ${account?.hash}")
        println("NEW HASH: $newHash")
        return newHash == account?.hash
    }

    override fun postHandle(
        request: HttpServletRequest,
        response: HttpServletResponse,
        handler: Any,
        modelAndView: ModelAndView?
    ) =
        super.postHandle(request, response, handler, modelAndView)


    override fun afterCompletion(
        request: HttpServletRequest,
        response: HttpServletResponse,
        handler: Any,
        ex: Exception?
    ) =
        super.afterCompletion(request, response, handler, ex)

}
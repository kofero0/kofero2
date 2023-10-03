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

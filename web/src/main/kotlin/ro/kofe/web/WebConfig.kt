package ro.kofe.web

import org.springframework.context.annotation.Configuration
import org.springframework.stereotype.Component
import org.springframework.stereotype.Service
import org.springframework.web.servlet.HandlerInterceptor
import org.springframework.web.servlet.ModelAndView
import org.springframework.web.servlet.config.annotation.InterceptorRegistry

import org.springframework.web.servlet.config.annotation.WebMvcConfigurer
import java.lang.Exception
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse


@Configuration
class WebConfig : WebMvcConfigurer {
    override fun addInterceptors(registry: InterceptorRegistry) {
        registry.addInterceptor(RequestInterceptor())
    }
}

@Service
class TestService() {

}

@Component
class RequestInterceptor: HandlerInterceptor {

    override fun preHandle(request: HttpServletRequest, response: HttpServletResponse, handler: Any) = super.preHandle(request, response, handler).also{
        println(request)
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
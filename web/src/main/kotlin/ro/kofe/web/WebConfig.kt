package ro.kofe.web

import org.springframework.beans.factory.annotation.Autowired
import org.springframework.context.annotation.Configuration
import org.springframework.web.servlet.config.annotation.InterceptorRegistry
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer


@Configuration
class WebConfig(
    @Autowired
    private val accountQueryService: AccountQueryService
) : WebMvcConfigurer {
    override fun addInterceptors(registry: InterceptorRegistry) {
        registry.addInterceptor(AuthInterceptor(accountQueryService))
            .addPathPatterns(ArrayList<String>().apply {
                add(GAME_PATH)
                add(CHAR_PATH)
                add(MOVE_PATH)
                add(COPY_PATH)
            })
    }
}

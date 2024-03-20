package ro.kofe.web

import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import java.io.InputStream

@RestController
class PrivacyController {
    private val stream: InputStream by lazy {
        ClassPathResource("data/privacy.html").inputStream
    }

    @GetMapping(PRIVACY_PATH)
    fun get(): ResponseEntity<Any> {
        return ResponseEntity<Any>(stream.bufferedReader().readText(),HttpStatus.OK)
    }
}
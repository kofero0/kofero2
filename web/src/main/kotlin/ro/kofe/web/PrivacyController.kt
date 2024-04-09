package ro.kofe.web

import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController

@RestController
class PrivacyController {
    private val resource = ClassPathResource("data/privacy.html")

    @GetMapping(PRIVACY_PATH)
    fun get(): ResponseEntity<Any> {
        return ResponseEntity<Any>(resource.inputStream.bufferedReader().readText(),HttpStatus.OK)
    }
}
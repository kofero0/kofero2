package ro.kofe.web

import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.PutMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RestController

@RestController
class AuthController {
    @PutMapping("/auth")
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        return ResponseEntity(HttpStatus.BAD_REQUEST)
    }
}
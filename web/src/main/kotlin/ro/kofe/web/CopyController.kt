package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Character
import java.io.InputStream

@RestController
class CopyController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }

    private val stream: InputStream by lazy {
        ClassPathResource("data/char.json").inputStream
    }


    @GetMapping(COPY_PATH)
    fun get(): ResponseEntity<Any> {
        return ResponseEntity<Any>(mapper.writeValueAsString(stream.bufferedReader().readText()), HttpStatus.OK)
    }
}
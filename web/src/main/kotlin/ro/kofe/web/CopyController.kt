package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import com.fasterxml.jackson.module.kotlin.readValue
import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Copy
import java.io.InputStream

@RestController
class CopyController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }

    private val stream: InputStream by lazy {
        ClassPathResource("data/copy.json").inputStream
    }


    @GetMapping(COPY_PATH)
    fun get(): ResponseEntity<Any> {
        return ResponseEntity<Any>(mapper.writeValueAsString(mapper.readValue<Copy>(stream.bufferedReader().readText())), HttpStatus.OK)
    }
}
package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Status
import java.util.*

@RestController
class StatusController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val properties: Properties by lazy {
        Properties().apply { load(this.javaClass.getResourceAsStream(RESOURCE)) }
    }

    @GetMapping("/status")
    fun status(): ResponseEntity<Any> {
        return ResponseEntity(
            mapper.writeValueAsString(
                Status(
                    time = System.currentTimeMillis(),
                    version = properties.getProperty(VERSION)
                )
            ), HttpStatus.OK
        )
    }

    companion object{
        private const val VERSION = "version"
        private const val RESOURCE = "$VERSION.properties"
    }
}
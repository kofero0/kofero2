package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Status

@RestController
class StatusController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }

    @GetMapping("/status")
    fun status(): ResponseEntity<Any>{
        return ResponseEntity(mapper.writeValueAsString(Status(System.currentTimeMillis(),"0.0.018"))  ,HttpStatus.OK)
    }
}
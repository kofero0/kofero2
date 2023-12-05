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
    private val service: StatusService by lazy {
        StatusService()
    }

    class StatusService {
        private val versionProperties = Properties()

        init {
            versionProperties.load(this.javaClass.getResourceAsStream(RESOURCE))
        }

        fun getVersion(): String = versionProperties.getProperty(VERSION) ?: "no version"
    }


    @GetMapping(STATUS_PATH)
    fun status(): ResponseEntity<Any> {
        return ResponseEntity(
            mapper.writeValueAsString(
                Status(
                    time = System.currentTimeMillis(),
                    version = service.getVersion()
                )
            ), HttpStatus.OK
        )
    }

    companion object {
        private const val VERSION = "version"
        private const val RESOURCE = "/$VERSION.properties"
    }
}
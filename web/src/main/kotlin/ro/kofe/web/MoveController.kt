package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.PutMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Move
import java.io.File


@RestController
class MoveController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val file: File by lazy {
        ClassPathResource("data/move.json").file
    }
    private val list: List<Move> by lazy {
        mapper.readValue(
            file.readText(), mapper.typeFactory
                .constructCollectionType(MutableList::class.java, Move::class.java)
        )
    }

    @PutMapping(MOVE_PATH)
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        val ret = ArrayList<Move>().apply {
            uids.forEach { uid ->
                this.add(list.first { uid == it.uid })
            }
        }
        return if (ret.size == uids.size) ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
        else ResponseEntity<Any>(HttpStatus.BAD_REQUEST)
    }
}
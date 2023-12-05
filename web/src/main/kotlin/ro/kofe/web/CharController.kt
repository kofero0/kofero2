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
import ro.kofe.model.Character
import java.io.File


@RestController
class CharController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val file: File by lazy {
        ClassPathResource("data/char.json").file
    }
    private val list: List<Character> by lazy {
        mapper.readValue(
            file.readText(), mapper.typeFactory
                .constructCollectionType(MutableList::class.java, Character::class.java)
        )
    }

    @PutMapping(CHAR_PATH)
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        val ret = ArrayList<Character>()
        run breaking@{
            list.forEach { char ->
                if (uids.contains(char.uid)) ret.add(char)
                if (ret.size == uids.size) return@breaking
            }
        }
        return if (ret.size == uids.size) ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
        else ResponseEntity<Any>(HttpStatus.BAD_REQUEST)
    }
}
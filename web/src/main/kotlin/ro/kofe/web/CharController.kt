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
import java.io.InputStream


@RestController
class CharController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val stream: InputStream by lazy {
        ClassPathResource("data/char.json").inputStream
    }
    private val list: List<Character> by lazy {
        mapper.readValue(
            stream.bufferedReader().readText(),
            mapper.typeFactory.constructCollectionType(MutableList::class.java, Character::class.java)
        )
    }

    @PutMapping(CHAR_PATH)
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        val ret = ArrayList<Character>().apply {
            uids.forEach { uid ->
                add(list.first { uid == it.uid })
            }
        }
        return if (ret.size == uids.size) ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
        else ResponseEntity<Any>(HttpStatus.BAD_REQUEST)
    }

    @PutMapping("$CHAR_PATH/search")
    fun search(@RequestBody query: List<String>): ResponseEntity<Any> {
        val ret = HashSet<Character>().apply {
            query.forEach { queryString ->
                list.forEach { char ->
                    if (char.name.lowercase()
                            .contains(queryString.lowercase()) || char.searchTerms.contains(queryString.lowercase())
                    ) {
                        add(char)
                    }
                }
            }
        }
        return ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
    }
}
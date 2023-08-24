package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.core.io.ClassPathResource
import org.springframework.web.bind.annotation.GetMapping
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

    @GetMapping("/char")
    fun get(@RequestBody uids: List<Int>): String {
        val ret = ArrayList<Character>()
        run breaking@{
            list.forEach { char ->
                if (uids.contains(char.uid)) {
                    ret.add(char)
                }
                if (ret.size == uids.size) return@breaking
            }
        }
        return mapper.writeValueAsString(ret)
    }
}
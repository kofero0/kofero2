package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.core.io.ClassPathResource
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.PutMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Game
import java.io.File


@RestController
class GameController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val file: File by lazy {
        ClassPathResource("data/game.json").file
    }
    private val list: List<Game> by lazy {
        mapper.readValue(
            file.readText(), mapper.typeFactory
                .constructCollectionType(MutableList::class.java, Game::class.java)
        )
    }

    @PutMapping(GAME_PATH)
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        if(uids.isEmpty()) return ResponseEntity<Any>(mapper.writeValueAsString(list),HttpStatus.OK)
        val ret = ArrayList<Game>()
        run breaking@{
            list.forEach { game ->
                if (uids.contains(game.uid)) ret.add(game)
                if (uids.size == ret.size) return@breaking
            }

        }
        return if(ret.size == uids.size) ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
        else ResponseEntity<Any>(HttpStatus.BAD_REQUEST)
    }
}
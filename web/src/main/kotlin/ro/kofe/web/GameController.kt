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
import ro.kofe.model.Game
import java.io.File
import java.io.InputStream


@RestController
class GameController {
    private val mapper: ObjectMapper by lazy {
        jsonMapper {
            addModule(kotlinModule())
        }
    }
    private val stream: InputStream by lazy {
        ClassPathResource("data/game.json").inputStream
    }
    private val list: List<Game> by lazy {
        mapper.readValue(
            stream.bufferedReader().readText(),
            mapper.typeFactory.constructCollectionType(MutableList::class.java, Game::class.java)
        )
    }

    @PutMapping(GAME_PATH)
    fun get(@RequestBody uids: List<Int>): ResponseEntity<Any> {
        if (uids.isEmpty()) {
            return ResponseEntity<Any>(mapper.writeValueAsString(list), HttpStatus.OK)
        }
        val ret = ArrayList<Game>().apply {
            uids.forEach { uid ->
                add(list.first { uid == it.uid })
            }
        }
        return if (ret.size == uids.size) ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
        else ResponseEntity<Any>(HttpStatus.BAD_REQUEST)
    }

    @PutMapping("$GAME_PATH/search")
    fun search(@RequestBody query: List<String>): ResponseEntity<Any> {
        val ret = HashSet<Game>().apply {
            query.forEach { queryString ->
                list.forEach { game ->
                    if (game.name.lowercase()
                            .contains(queryString.lowercase()) || game.searchTerms.contains(queryString.lowercase())
                    ) {
                        add(game)
                    }
                }
            }
        }
        return ResponseEntity<Any>(mapper.writeValueAsString(ret), HttpStatus.OK)
    }
}
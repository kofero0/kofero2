package ro.kofe.web

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.databind.type.CollectionType
import com.fasterxml.jackson.module.kotlin.jsonMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.springframework.core.io.ClassPathResource
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.Game
import java.io.File


@RestController
class GameController {
    private val mapper: ObjectMapper
    private val file: File


    init {
        mapper = jsonMapper {
            addModule(kotlinModule())
        }
        file = ClassPathResource("data/game.json").file
    }

    @GetMapping("/game")
    fun get(): String {
        val javaType: CollectionType = mapper.typeFactory
            .constructCollectionType(MutableList::class.java, Game::class.java)
        val list: List<Game> = mapper.readValue(file.readText(),javaType)
        return "file: ${mapper.writeValueAsString(list[0])}"
    }
}
package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Character
import ro.kofe.presenter.map.Mapper
import java.nio.charset.Charset


class CharacterMapper(private val gson: Gson) : Mapper<List<Character>, String> {
    private val typeToken = object : TypeToken<ArrayList<Character>>() {}.type

    override fun mapRight(data: List<Character>): String =
        gson.toJson(data)

    override fun mapLeft(data: String): List<Character> =
        gson.fromJson(data, typeToken)
}
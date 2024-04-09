package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Game
import ro.kofe.presenter.map.Mapper


class GameMapper(private val gson: Gson) : Mapper<List<Game>, String> {
    private val typeToken = object : TypeToken<ArrayList<Game>>() {}.type

    override fun mapRight(data: List<Game>): String =
        gson.toJson(data)

    override fun mapLeft(data: String): List<Game> =
        gson.fromJson(data, typeToken)
}
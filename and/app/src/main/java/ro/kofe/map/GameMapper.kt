package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Game
import java.nio.charset.Charset


class GameMapper(private val gson: Gson) : Mapper<List<Game>, ByteArray> {
    private val typeToken = object : TypeToken<ArrayList<Game>>() {}.type

    override fun mapRight(data: List<Game>) =
        gson.toJson(data).toByteArray(Charset.defaultCharset())

    override fun mapLeft(data: ByteArray): List<Game> =
        gson.fromJson(String(data, Charset.defaultCharset()), typeToken)
}
package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Move
import ro.kofe.presenter.map.Mapper


class MoveMapper(private val gson: Gson) : Mapper<List<Move>, String> {
    private val typeToken = object : TypeToken<ArrayList<Move>>() {}.type

    override fun mapRight(data: List<Move>): String =
        gson.toJson(data)

    override fun mapLeft(data: String): List<Move> =
        gson.fromJson(data, typeToken)
}
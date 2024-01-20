package ro.kofe.map

import com.google.gson.Gson
import ro.kofe.presenter.map.Mapper

class RequestMapper(private val gson: Gson): Mapper<List<Int>, String> {
    override fun mapRight(data: List<Int>) = gson.toJson(data).toString()

    override fun mapLeft(data: String): List<Int> {
        //NOOP
        return emptyList()
    }
}
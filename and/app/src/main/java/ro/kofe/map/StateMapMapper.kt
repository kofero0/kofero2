package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Event
import ro.kofe.presenter.map.Mapper
import java.nio.charset.Charset

class StateMapMapper(private val gson: Gson) : Mapper<Map<Long, Event>, ByteArray> {
    private val typeToken = object : TypeToken<HashMap<Long, Event>>() {}.type

    override fun mapRight(data: Map<Long, Event>) =
        gson.toJson(data).toByteArray(Charset.defaultCharset())

    override fun mapLeft(data: ByteArray): Map<Long, Event> =
        gson.fromJson(String(data, Charset.defaultCharset()), typeToken)
}
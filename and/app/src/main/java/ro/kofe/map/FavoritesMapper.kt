package ro.kofe.map

import com.google.gson.Gson
import com.google.gson.JsonElement
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Obj
import java.nio.charset.Charset


class FavoritesMapper(private val gson: Gson) : Mapper<List<Obj>, ByteArray> {
    private val typeToken = object : TypeToken<ArrayList<JsonElement>>() {}.type

    override fun mapRight(data: List<Obj>) = gson.toJson(data).toByteArray(Charset.defaultCharset())

    override fun mapLeft(data: ByteArray): List<Obj> {
        val elementList: List<JsonElement> =
            gson.fromJson(String(data, Charset.defaultCharset()), typeToken)
        val ret = ArrayList<Obj>()
        for (element in elementList) {
            if (element.asJsonObject.has("moveIds")) {
                ret.add(gson.fromJson(element, Character::class.java))
            }
            if (element.asJsonObject.has("charIds")) {
                ret.add(gson.fromJson(element, Game::class.java))
            }
        }
        return ret
    }
}
package ro.kofe.map

import com.google.gson.Gson
import ro.kofe.model.Copy
import ro.kofe.presenter.map.Mapper

class CopyMapper(private val gson: Gson) : Mapper<Copy, String> {
    override fun mapRight(data: Copy): String = gson.toJson(data)
    override fun mapLeft(data: String): Copy = gson.fromJson(data, Copy::class.java)
}
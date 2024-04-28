package ro.kofe.map

import com.google.gson.Gson
import ro.kofe.model.Status
import ro.kofe.presenter.map.Mapper

class StatusMapper(private val gson:Gson): Mapper<Status, String> {
    override fun mapRight(data: Status): String = gson.toJson(data)

    override fun mapLeft(data: String): Status = gson.fromJson(data, Status::class.java)
}
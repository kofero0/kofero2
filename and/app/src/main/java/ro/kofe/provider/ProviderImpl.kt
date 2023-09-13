package ro.kofe.provider

import android.content.Context
import android.util.Log
import arrow.core.raise.either
import com.google.gson.Gson
import kotlinx.coroutines.flow.flow
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody
import okhttp3.internal.http2.Header
import ro.kofe.map.Mapper
import ro.kofe.model.HttpError
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.Provider
import java.io.File


class ProviderImpl<O : Obj>(
    private val gson: Gson,
    private val okHttp: OkHttpClient,
    private val context: Context,
    private val jsonFilename: String,
    private val urlPrefix: String,
    private val mapper: Mapper<List<O>, ByteArray>
) : Provider<O> {
    private var isDiskPulled = false
    private var elements: MutableList<O> = ArrayList()
    private val file: File by lazy {
        File(
            context.filesDir, "$jsonFilename.json"
        ).apply {
            if (!exists()) createNewFile()
            writeBytes("[]".toByteArray())
        }
    }

    override fun get(ids: List<Int>) = flow {
        if(!isDiskPulled) {
            isDiskPulled = true
            elements = mapper.mapLeft(file.readBytes()).toMutableList()
        }
        if(isSatisfiable(ids)) emit(retrieve(ids))
        emit(send(ids))
    }

    private fun send(ids: List<Int>) =
        either{
            val response = okHttp.newCall(
                Request.Builder().url("$urlPrefix/$jsonFilename")
                    .header("Content-Type","application/json")
                    .put(gson.toJson(ids).toRequestBody()).build()
            ).execute()
            if (response.isSuccessful && response.body != null) {
                mapper.mapLeft(response.body!!.bytes()).also { add(it) }
            } else {
                raise(HttpError(response.code, response.body.toString()))
            }
        }

    private fun add(new: List<O>) {
        for (element in new) {
            elements.removeAll { it.uid == element.uid }
            elements.add(element)
        }
        if (!file.exists()) {
            file.mkdir()
        }
        file.writeBytes(mapper.mapRight(elements))
    }

    private fun retrieve(ids: List<Int>) =
        either<ProviderError, List<O>> {
            if (ids.isEmpty()) {
                elements
            } else {
                ArrayList<O>().apply {
                    for (id in ids) {
                        add(elements.first { it.uid == id })
                    }
                }
            }
        }

    private fun isSatisfiable(ids: List<Int>): Boolean {
        for (id in ids) {
            if (elements.none { it.uid == id }) {
                return false
            }
        }
        return true
    }
}
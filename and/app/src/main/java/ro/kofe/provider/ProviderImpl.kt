package ro.kofe.provider

import android.accounts.NetworkErrorException
import android.content.Context
import arrow.core.raise.ior
import com.google.gson.Gson
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody
import ro.kofe.map.Mapper
import ro.kofe.model.CombinedError
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
        ).apply { if (!exists()) mkdir() }
    }

    override suspend fun get(ids: List<Int>) =
        ior<ProviderError, List<O>>({ e1, e2 -> CombinedError(e1, e2) }) {
            if (!isDiskPulled) {
                isDiskPulled = true
                elements = mapper.mapLeft(file.readBytes()).toMutableList()
                if (isSatisfiable(ids)) {
                    retrieve(ids)
                } else {
                    send(ids)
                }
            } else {
                if (isSatisfiable(ids)) retrieve(ids)
                else send(ids)
            }
        }

    private fun send(ids: List<Int>): List<O> {
        val request =
            Request.Builder().url(urlPrefix + jsonFilename).put(gson.toJson(ids).toRequestBody())
                .build()
        val response = okHttp.newCall(request).execute()
        if (response.isSuccessful) {
            response.body?.let {
                val ret = mapper.mapLeft(it.bytes())
                add(ret)
                return ret
            }
        }
        throw NetworkErrorException()
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

    private fun retrieve(ids: List<Int>): List<O> = if (ids.isEmpty()) {
        elements
    } else {
        var ret = ArrayList<O>()
        for (id in ids) {
            ret.add(elements.first { it.uid == id })
        }
        ret
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
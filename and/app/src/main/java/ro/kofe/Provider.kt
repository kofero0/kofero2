package ro.kofe

import android.content.Context
import arrow.core.Ior
import arrow.core.raise.either
import arrow.core.raise.ior
import com.google.gson.Gson
import okhttp3.*
import okhttp3.RequestBody.Companion.toRequestBody
import ro.kofe.model.Obj
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.Provider
import ro.kofe.map.Mapper
import ro.kofe.model.HttpError
import ro.kofe.model.OtherError
import java.io.File
import java.io.IOException


class Provider<O : Obj>(
    private val gson: Gson,
    private val okHttp: OkHttpClient,
    private val context: Context,
    private val jsonFilename: String,
    private val mapper: Mapper<List<O>, ByteArray>
) : Provider<O> {
    private var isDiskPulled = false
    private var elements: MutableList<O> = ArrayList()

    override suspend fun get(ids: List<Int>) = ior<ProviderError, List<O>>({e1, e2 -> OtherError }) {
        raise(OtherError)
    }

    /*
    override suspend fun get(ids: List<Int>): Ior<ProviderError, List<O>> {
        if (!isDiskPulled) {
            pullFromDisk(ids)
        } else {
            if (isSatisfiable(ids)) informListeners(ids, retrieve(ids))
            else send(ids)
        }
    }
     */

    private fun send(ids: List<Int>) {
        okHttp.newCall(makeRequest(ids)).enqueue(makeCallback(ids))
    }

    private fun makeRequest(ids: List<Int>): Request {
        return Request.Builder().url(jsonFilename).put(gson.toJson(ids).toRequestBody()).build()
    }

    private fun makeCallback(ids: List<Int>): Callback {
        return object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                informListenersError(ids, e)
            }

            override fun onResponse(call: Call, response: Response) {
                if (response.isSuccessful) {
                    try {
                        response.body?.let { add(mapper.mapLeft(it.bytes())) }
                    } catch (e: Exception) {
                        informListenersError(ids, e)
                    }
                }
                response.body?.bytes()
            }
        }
    }

    private fun add(new: List<O>) {
        for (element in new) {
            elements.removeAll { it.uid == element.uid }
            elements.add(element)
        }
        saveToDisk()

    }


    private fun saveToDisk() {
        try {
            val file = File(context.filesDir.absolutePath + "/$jsonFilename")
            if (!file.exists()){

            }
        } catch (e: Exception) {

        }
    }

    /*
    private func saveToDisk(){
        do{
            try mapper.map(data: elements).write(to: makeUrl(string: jsonFilename), options: .atomic)
        }
        catch {
            informListenersError(ids: [], error: KotlinException(error: error))
        }
    }
     */
    /*
    private func add(new:[O]){
        for element in new {
            elements.removeAll(where: {existingElement in return element.uid == existingElement.uid})
            elements.append(element)
        }
        saveToDisk()
        for request in requests.keys {
            if(isSatisfiable(request: request)){
                informListeners(ids: request, elements: retrieve(ids: request))
                requests.removeValue(forKey: request)?.cancel()
            }
        }
    }
     */

    /*
    private func getRestClosure(ids: [KotlinInt]) -> RestClosure {
        return {[self] data, response, error in
            if(isResponseGood(data:data, response:response, error:error)){
                do{ add(new: try mapper.map(data: data!)) }
                catch { informListenersError(ids: ids, error: KotlinException(message: error.localizedDescription)) }
            }
            else{
                informListenersError(ids: ids, error: KotlinException(message: "error:\(error.debugDescription), response: \(response.debugDescription)"))
            }
        }
    }
     */

    private fun retrieve(ids: List<Int>): List<O> {
        if (ids.isEmpty()) {
            return elements
        }
        var ret = ArrayList<O>()
        for (id in ids) {
            ret.add(elements.first { it.uid == id })
        }
        return ret
    }

    private fun isSatisfiable(ids: List<Int>): Boolean {
        for (id in ids) {
            if (elements.none { it.uid == id }) {
                return false
            }
        }
        return true
    }

    private fun pullFromDisk(ids: List<Int>) {
        isDiskPulled = true
        val file = File(context.filesDir, jsonFilename)
        try {
            elements = mapper.mapLeft(file.readBytes()).toMutableList()
        } catch (e: Exception) {
            informListenersError(ids, e)
        }
        if (isSatisfiable(ids)) {
            informListeners(ids, retrieve(ids))
        } else {
            send(ids)
        }
    }
}
package ro.kofe.presenter.provider

import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import kotlinx.coroutines.InternalCoroutinesApi
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.internal.SynchronizedObject
import kotlinx.coroutines.internal.synchronized
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.presenter.map.Mapper

@OptIn(InternalCoroutinesApi::class)
abstract class ProviderAbstract<T>(
    private val client: HttpClient,
    private val jsonFilename: String,
    private val urlPrefix: String,
    private val mapper: Mapper<List<T>, String>,
    private val requestMapper: Mapper<List<Int>, String>,
    private val searchRequestMapper: Mapper<List<String>, String>,
    private val diskAccessor: DiskAccessor
) : Provider<T> {
    private var isDiskPulled = false
    private var elements: MutableList<T> = ArrayList()
    private val syncObject = SynchronizedObject()

    override fun get(ids: List<Int>) = flow {
        if (!isDiskPulled) {
            isDiskPulled = true
            elements = mapper.mapLeft(diskAccessor.read(jsonFilename)).toMutableList()
        }
        if (isSatisfiable(ids)) {
            emit(retrieve(ids))
        } else {
            emit(send(requestMapper.mapRight(ids)))
        }
    }

    override fun search(query: List<String>) = flow {
        emit(send(searchRequestMapper.mapRight(query)))
    }

    override fun delete() = either<ProviderError, Unit> {
        diskAccessor.write(jsonFilename,"")
    }

    private suspend fun send(body:String) = either {
        val response = client.put("$urlPrefix/$jsonFilename") {
            contentType(ContentType.Application.Json)
            setBody(body)
        }
        if (response.status.value in 200..299) {
            mapper.mapLeft(response.bodyAsText()).also { add(it) }
        } else {
            raise(HttpError(response.status.value, response.bodyAsText()))
        }
    }

    private fun add(new: List<T>) {
        synchronized(syncObject) {
            for (element in new) {
                elements.removeAll { isEqual(it, element) }
                elements.add(element)
            }
            diskAccessor.write(jsonFilename, mapper.mapRight(elements))
        }
    }

    private fun retrieve(ids: List<Int>) = either<ProviderError, List<T>> {
        synchronized(syncObject) {
            if (ids.isEmpty()) {
                elements
            } else {
                ArrayList<T>().apply {
                    for (id in ids) {
                        add(elements.first { isEqual(it, id) })
                    }
                }
            }
        }
    }

    private fun isSatisfiable(ids: List<Int>): Boolean {
        if (elements.isEmpty()) return false
        for (id in ids) {
            if (elements.none { isEqual(it, id) }) {
                return false
            }
        }
        return true
    }

    abstract fun isEqual(element: T, id: Int): Boolean

    abstract fun isEqual(one: T, two: T): Boolean
}
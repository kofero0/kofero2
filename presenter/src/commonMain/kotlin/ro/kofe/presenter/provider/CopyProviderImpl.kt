

package ro.kofe.presenter.provider

import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import kotlinx.coroutines.InternalCoroutinesApi
import kotlinx.coroutines.internal.SynchronizedObject
import kotlinx.coroutines.internal.synchronized
import ro.kofe.model.Copy
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.presenter.map.Mapper

@OptIn(InternalCoroutinesApi::class)
class CopyProviderImpl(
    private val client: HttpClient,
    private val jsonFilename: String,
    private val urlPrefix: String,
    private val mapper: Mapper<Copy, String>,
    private val diskAccessor: DiskAccessor
) : CopyProvider {
    private var isDiskPulled = false
    private var copy: Copy? = null
    private val syncObject = SynchronizedObject()

    private fun isEmpty(copy: Copy): Boolean {
        return copy.about == "" && copy.acknowledgment == "" && copy.privacyPolicyUrl == ""
    }

    override suspend fun get() = either<ProviderError,Copy>{
        synchronized(syncObject) {
            if (!isDiskPulled) {
                isDiskPulled = true
                copy = mapper.mapLeft(diskAccessor.read(jsonFilename))
            }
            if (copy == null || isEmpty(copy!!)) {
                val response = client.get("$urlPrefix/copy") {
                contentType(ContentType.Application.Json)
            }
                if (response.status.value in 200..299) {
                    mapper.mapLeft(response.bodyAsText()).also {
                        copy = it
                    }
                } else {
                    raise(HttpError(response.status.value, response.bodyAsText()))
                }
            } else {
                copy!!
            }
        }
    }

    override fun delete() = either<ProviderError, Unit> {
        diskAccessor.write(jsonFilename, "")
    }
}
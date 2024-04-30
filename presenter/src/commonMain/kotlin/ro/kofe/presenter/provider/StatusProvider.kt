package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError
import ro.kofe.model.Status
import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import ro.kofe.model.HttpError
import ro.kofe.presenter.map.Mapper

interface StatusProvider {
    suspend fun getBackendStatus(): Either<ProviderError, Status>
    fun getLocalStatus(): Status
}

abstract class AbstractStatusProvider(
    private val client: HttpClient,
    private val urlPrefix: String,
    private val mapper:Mapper<Status, String>,
    private val diskAccessor: DiskAccessor
): StatusProvider {

    override suspend fun getBackendStatus() = either {
        val response = client.get("$urlPrefix/status"){
            contentType(ContentType.Application.Json)
        }
        if(response.status.value in 200..299){
            val body = response.bodyAsText()
            diskAccessor.write(FILENAME,body)
            mapper.mapLeft(body)
        } else {
            raise(HttpError(response.status.value,response.bodyAsText()))
        }
    }

    override fun getLocalStatus() =
        if(diskAccessor.read(FILENAME).isEmpty()){
            Status(999L,"0.0.0")
        }else{
            mapper.mapLeft(diskAccessor.read(FILENAME))
        }

    companion object {
        private const val FILENAME = "status"
    }
}
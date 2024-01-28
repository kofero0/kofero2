package ro.kofe.presenter.provider

import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import ro.kofe.model.HttpError
import ro.kofe.model.Status
import ro.kofe.presenter.map.Mapper

abstract class AbstractStatusProvider(
    private val client: HttpClient,
    private val urlPrefix: String,
    private val mapper:Mapper<Status, String>
): StatusProvider {


    override suspend fun getBackendStatus() = either {
        val response = client.get("$urlPrefix/status"){
            contentType(ContentType.Application.Json)
        }
        if(response.status.value in 200..299){
            mapper.mapLeft(response.bodyAsText())
        } else {
            raise(HttpError(response.status.value,response.bodyAsText()))
        }
    }

    abstract override fun getLocalStatus(): Status
}
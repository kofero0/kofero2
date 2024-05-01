package ro.kofe.presenter.provider

import arrow.core.Either
import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import io.ktor.utils.io.core.*
import ro.kofe.model.HttpError
import ro.kofe.model.OtherError
import ro.kofe.model.ProviderError
import kotlin.io.encoding.Base64
import kotlin.io.encoding.ExperimentalEncodingApi

interface ImageProvider {
    suspend fun get(url: String): Either<ProviderError, String>
}

@OptIn(ExperimentalEncodingApi::class)
class ImageProviderImpl(private val client: HttpClient, private val diskAccessor: DiskAccessor) :
    ImageProvider {
    override suspend fun get(url: String) = either<ProviderError,String> {
        if(!diskAccessor.exists("${url.hashCode()}")){
            val response = client.get(url)
            if(response.status == HttpStatusCode.OK){
                val bytes = Base64.encode(response.readBytes())
                diskAccessor.write("${url.hashCode()}",bytes)
            }
            else{
                HttpError(response.status.value, response.bodyAsText())
            }
        }
        diskAccessor.read("${url.hashCode()}")
    }
}
package ro.kofe.presenter.provider

import arrow.core.Either
import ro.kofe.model.ProviderError


import arrow.core.raise.either
import io.ktor.client.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.http.*
import kotlinx.coroutines.InternalCoroutinesApi
import kotlinx.coroutines.internal.SynchronizedObject
import kotlinx.coroutines.internal.synchronized
import kotlinx.coroutines.runBlocking
import ro.kofe.model.HttpError


interface AuthProvider {
    fun get(): Either<ProviderError, String>
    fun delete(): Either<ProviderError, Unit>
}

interface AuthMapper {
    fun getAuthToken(jsonString: String): String
}

interface AuthDiskAccessor {
    fun read(): String
    fun save(token: String)
}


interface IdentityProvider {
    fun getDeviceId(): String
}


@OptIn(InternalCoroutinesApi::class)
class AuthProviderImpl(
    private val client: HttpClient,
    private val urlPrefix: String,
    private val diskAccessor: AuthDiskAccessor,
    private val authMapper: AuthMapper,
    private val identityProvider: IdentityProvider
) : AuthProvider {
    private val syncObject = SynchronizedObject()

    override fun get() = either {
        synchronized(syncObject) {
            diskAccessor.read().ifEmpty {
                runBlocking {
                    val response = client.put("$urlPrefix/auth/register") {
                        contentType(ContentType.Application.Json)
                        setBody("{\"prefixedUid\":\"koferoAuth||${identityProvider.getDeviceId()}\"}")
                    }
                    if (response.status.value in 200..299) {
                        val token = authMapper.getAuthToken(response.bodyAsText())
                        diskAccessor.save(token)
                        token
                    } else {
                        raise(HttpError(response.status.value, response.status.toString()))
                    }
                }
            }
        }
    }

    override fun delete() = either<ProviderError,Unit> {
        synchronized(syncObject){
            diskAccessor.save("")
        }
    }
}
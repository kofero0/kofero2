package ro.kofe.provider

import android.content.Context
import android.util.Log
import arrow.core.Either
import arrow.core.raise.either
import com.google.gson.Gson
import kotlinx.coroutines.future.await
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.model.authDelimiter
import ro.kofe.model.authPrefix
import ro.kofe.model.request.RegisterAuthRequest
import ro.kofe.model.response.RegisterAuthResponse
import ro.kofe.presenter.provider.AuthProvider
import java.io.File
import java.util.concurrent.CompletableFuture

class AuthProviderImpl(
    private val gson: Gson,
    private val identityProvider: IdentityProvider,
    private val client: OkHttpClient,
    private val urlPrefix: String,
    private val context: Context
) : AuthProvider {
    private val file: File by lazy {
        File(
            context.filesDir, AUTH
        ).apply {
            if (!exists()) {
                createNewFile()
            }
        }
    }
    private var isWaitingForAuth = false
    private var future = CompletableFuture<String>()

    override suspend fun get() = either {
        file.readText().ifEmpty {
            if (!isWaitingForAuth) {
                isWaitingForAuth = true
                val response = client.newCall(
                    Request.Builder().url("$urlPrefix/$AUTH/$REG").put(
                        gson.toJson(
                            RegisterAuthRequest("$authPrefix$authDelimiter${identityProvider.getDeviceId()}")
                        ).toRequestBody()
                    ).header("Content-Type", "application/json").build()
                ).execute()

                if (response.isSuccessful && response.body != null) {
                    val response = response.body?.string()
                    val token =
                        gson.fromJson(
                            response,
                            RegisterAuthResponse::class.java
                        ).token
                    file.writeText(token)
                    future.complete(token)
                    isWaitingForAuth = false
                    token
                } else {
                    raise(HttpError(response.code, response.body.toString()))
                }
            } else {
                future.await()
            }
        }
    }

    companion object {
        private const val AUTH = "auth"
        private const val REG = "register"
    }
}
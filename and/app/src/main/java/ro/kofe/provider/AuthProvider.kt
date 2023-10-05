package ro.kofe.provider

import android.content.Context
import arrow.core.Either
import arrow.core.raise.either
import com.google.gson.Gson
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.future.await
import kotlinx.coroutines.launch
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.model.authDelimiter
import ro.kofe.model.authPrefix
import ro.kofe.model.request.RegisterAuthRequest
import ro.kofe.model.response.RegisterAuthResponse
import ro.kofe.presenter.DispatcherProvider
import java.io.File
import java.util.concurrent.CompletableFuture

interface AuthProvider {
    suspend fun get(): Either<ProviderError, String>
}

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
            if (!exists()) createNewFile()
            writeBytes("".toByteArray())
        }
    }

    override suspend fun get() = either {
        file.readBytes().toString().ifEmpty {
            val response = client.newCall(
                Request.Builder().url("$urlPrefix/$AUTH/$REG").put(
                    gson.toJson(
                        RegisterAuthRequest("$authPrefix$authDelimiter${identityProvider.getDeviceId()}")
                    ).toRequestBody()
                ).build()
            ).execute()

            if (response.isSuccessful && response.body != null) {
                val token =
                    gson.fromJson(response.body!!.string(), RegisterAuthResponse::class.java).token
                file.writeBytes(token.toByteArray())
                token
            } else {
                raise(HttpError(response.code, response.body.toString()))
            }
        }
    }

    companion object {
        private const val AUTH = "auth"
        private const val REG = "register"
    }
}
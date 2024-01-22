package ro.kofe.presenter

import io.ktor.client.*
import io.ktor.client.engine.okhttp.*
import io.ktor.client.plugins.*
import ro.kofe.presenter.provider.AuthProvider

object HttpClientProvider {
    fun provideAuth(authProvider: AuthProvider): HttpClient {
        val client = HttpClient(OkHttp)
        client.plugin(HttpSend).intercept { request ->
            authProvider.get().map { authToken ->
                request.headers.append("Authorization", authToken )
            }
            execute(request)
        }
        return client
    }

    fun provideNoAuth() = HttpClient(OkHttp)
}
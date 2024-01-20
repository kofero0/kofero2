package ro.kofe.presenter

import io.ktor.client.*
import io.ktor.client.engine.okhttp.*
import io.ktor.client.plugins.*

object HttpClientProvider {
    fun provide(): HttpClient {
        val client = HttpClient(OkHttp)
//        client.plugin(HttpSend).intercept {
//
//        }
        return client
    }
}
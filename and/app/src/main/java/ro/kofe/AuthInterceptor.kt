package ro.kofe

import android.util.Log
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch
import okhttp3.Interceptor
import okhttp3.Request
import okhttp3.Response
import ro.kofe.model.HeaderKeys
import ro.kofe.model.logging.Level
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.provider.AuthProvider
import java.net.ConnectException
import java.util.concurrent.CompletableFuture

class AuthInterceptor(
    private val authProvider: AuthProvider,
    private val dispatcherProvider: DispatcherProvider,
    private val loggingProvider: LoggingProvider
) :
    Interceptor {
    override fun intercept(chain: Interceptor.Chain): Response {
        val request = chain.request()
        val future = CompletableFuture<Request>()
        CoroutineScope(dispatcherProvider.default).launch {
            try {
                authProvider.get().map {
                    future.complete(
                        request.newBuilder().header(HeaderKeys.AUTHORIZATION, it).build()
                    )
                }
            } catch (e: ConnectException) {
                loggingProvider.log(
                    Level.ALERT,
                    "AuthInterceptor",
                    "connection refused: ${e.printStackTrace()}"
                )
            }
        }
        return chain.proceed(future.get())
    }
}
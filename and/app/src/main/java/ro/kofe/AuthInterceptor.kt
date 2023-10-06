package ro.kofe

import android.util.Log
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.async
import kotlinx.coroutines.future.await
import kotlinx.coroutines.launch
import okhttp3.Interceptor
import okhttp3.Request
import okhttp3.Response
import ro.kofe.model.HeaderKeys
import ro.kofe.presenter.DispatcherProvider
import ro.kofe.provider.AuthProvider
import java.util.concurrent.CompletableFuture

class AuthInterceptor(private val authProvider: AuthProvider, private val dispatcherProvider: DispatcherProvider): Interceptor {
    override fun intercept(chain: Interceptor.Chain): Response {
        val request = chain.request()
        val future = CompletableFuture<Request>()
        CoroutineScope(dispatcherProvider.default).launch {
            authProvider.get().map {
                Log.v("rwr", "authToken: $it")
                future.complete(
                    request.newBuilder().header(HeaderKeys.AUTHORIZATION, it).build()
                )
            }
        }
        return chain.proceed(future.get())
    }
}
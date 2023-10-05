package ro.kofe

import okhttp3.Interceptor
import okhttp3.Request
import okhttp3.Response
import ro.kofe.model.logging.Level
import ro.kofe.presenter.provider.LoggingProvider

class LoggingInterceptor(private val logger: LoggingProvider) : Interceptor {
    override fun intercept(chain: Interceptor.Chain): Response {
        val request: Request = chain.request()
        val t1 = System.nanoTime()
        logger.log(
            Level.DEBUG,
            TAG,
            "Sending request to ${request.url} on ${request.url}${chain.connection()}${request.headers}"
        )
        val response = chain.proceed(request)
        val t2 = System.nanoTime()
        logger.log(Level.DEBUG, TAG, "Received response to ${response.request.url} in (${t2 - t1})")
        return response
    }

    companion object {
        const val TAG = "LoggingInterceptor"
    }
}
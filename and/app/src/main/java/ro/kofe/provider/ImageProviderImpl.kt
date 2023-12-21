package ro.kofe.provider

import android.content.Context
import android.util.Log
import arrow.core.raise.either
import okhttp3.OkHttpClient
import okhttp3.Request
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.ImageProvider
import java.io.File

class ImageProviderImpl(private val okHttp: OkHttpClient, context: Context) :
    ImageProvider {
    private val imgDir: File by lazy {
        File(
            context.filesDir,
            "img"
        ).apply { if (!exists()) mkdirs() }
    }


    override suspend fun get(url: String) = either<ProviderError, String> {
        val file = File(imgDir, "${url.hashCode()}")
        if (!file.exists()) {
            val response = okHttp.newCall(Request.Builder().url(url).build()).execute()
            if (response.isSuccessful) {
                response.body?.let {
                    Log.v("rwr", "${file.absolutePath}")
                    val bytes = it.bytes()
                    file.createNewFile()
                    file.writeBytes(bytes)
                    bytes
                }
                HttpError(response.code, response.body.toString())
            } else {
                HttpError(response.code, response.body.toString())
            }
        }
        file.readText()
    }
}
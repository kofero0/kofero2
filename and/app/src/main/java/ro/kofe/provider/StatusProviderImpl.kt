package ro.kofe.provider

import arrow.core.raise.either
import com.google.gson.Gson
import io.ktor.client.HttpClient
import okhttp3.OkHttpClient
import okhttp3.Request
import ro.kofe.frames.BuildConfig
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.model.Status
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.provider.AbstractStatusProvider
import ro.kofe.presenter.provider.DiskAccessor
import ro.kofe.presenter.provider.StatusProvider

class StatusProviderImpl(
    private val client: OkHttpClient, private val urlPrefix: String, private val gson: Gson
) : StatusProvider {
    override suspend fun getBackendStatus() = either<ProviderError, Status> {
        val response = client.newCall(
            Request.Builder().url("$urlPrefix/$statusSuffix").get().build()
        ).execute()
        if (response.isSuccessful && response.body != null) {
            gson.fromJson(response.body!!.string(), Status::class.java)
        } else {
            raise(HttpError(response.code, response.body?.string().toString()))
        }
    }

    override fun getLocalStatus() = Status(System.nanoTime(), BuildConfig.VERSION_NAME)

    companion object {
        private const val statusSuffix = "status"
    }
}

class ConcreteStatusProvider(client:HttpClient, urlPrefix:String, mapper: Mapper<Status, String>,diskAccessor: DiskAccessor): AbstractStatusProvider(client,urlPrefix,mapper,diskAccessor)
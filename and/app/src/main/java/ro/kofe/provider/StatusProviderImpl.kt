package ro.kofe.provider

import android.content.Context
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
import java.io.File

class ConcreteStatusProvider(client:HttpClient, urlPrefix:String, mapper: Mapper<Status, String>,diskAccessor: DiskAccessor): AbstractStatusProvider(client,urlPrefix,mapper,diskAccessor)

class StatusProviderDiskAccessor(private val context: Context, gson:Gson): DiskAccessorImpl(context, gson.toJson(Status(0L,"0.0.0")))
package ro.kofe.view

import com.google.common.collect.ImmutableMap
import io.ktor.util.collections.CopyOnWriteHashMap
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.presenter.ipv.ImageKView
import ro.kofe.presenter.ipv.Interactor

abstract class ImageViewModel(interactor: Interactor<out ImageKView>) : KViewModel(interactor),
    ImageKView {
    private val _images = MutableStateFlow<Map<String, String>>(HashMap())
    val images = _images.asStateFlow()

    override suspend fun display(url: String, imgBase64: String) = _images.update {
        HashMap<String, String>().apply {
            putAll(_images.value)
            put(url,imgBase64)
        }
    }
}
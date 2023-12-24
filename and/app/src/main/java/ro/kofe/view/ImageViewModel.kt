package ro.kofe.view

import android.util.Log
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.presenter.ipv.ImageKView
import ro.kofe.presenter.ipv.Interactor

abstract class ImageViewModel(interactor: Interactor<out ImageKView>) : KViewModel(interactor),
    ImageKView {
    private val _images = MutableStateFlow<MutableMap<String, String>>(HashMap())
    val images = _images.asStateFlow()

    override fun display(url: String, imgBase64: String) = _images.update {
        Log.v("rwr", "display Images: $url")
        _images.value.apply { put(url, imgBase64) }
    }
}
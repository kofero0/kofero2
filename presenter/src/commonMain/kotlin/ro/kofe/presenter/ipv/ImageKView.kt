package ro.kofe.presenter.ipv

interface ImageKView : KView {
    suspend fun display(url: String, imgBase64: String)
}
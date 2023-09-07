package ro.kofe.presenter.ipv

interface ImageKView : KView {
    fun display(url: String, imgBase64: String)
}
package ro.kofe.presenter.provider

interface AuthDiskAccessor {
    fun read(): String
    fun save(token: String)
}
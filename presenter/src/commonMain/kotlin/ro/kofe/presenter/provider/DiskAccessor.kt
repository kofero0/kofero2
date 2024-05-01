package ro.kofe.presenter.provider

interface DiskAccessor {
    fun exists(url: String): Boolean
    fun read(fileName:String): String
    fun write(fileName:String, payload:String)
}
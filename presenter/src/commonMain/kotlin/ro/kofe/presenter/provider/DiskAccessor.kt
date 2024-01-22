package ro.kofe.presenter.provider

interface DiskAccessor {
    fun read(fileName:String): String
    fun write(fileName:String, json:String)
}
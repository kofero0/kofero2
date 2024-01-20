package ro.kofe.presenter.provider

interface DiskAccessor {
    fun read(jsonFilename:String): String
    fun write(json:String): Boolean
}
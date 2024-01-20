package ro.kofe.provider

import android.content.Context
import ro.kofe.presenter.provider.DiskAccessor

class DiskAccessorImpl(private val context: Context): DiskAccessor {
    override fun read(jsonFilename: String): String {
        TODO("Not yet implemented")
    }

    override fun write(json: String): Boolean {
        TODO("Not yet implemented")
    }
}
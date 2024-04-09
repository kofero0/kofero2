package ro.kofe.provider

import android.content.Context
import ro.kofe.presenter.provider.DiskAccessor
import java.io.File

class DiskAccessorImpl(private val context: Context, private val new:String = "[]") : DiskAccessor {
    override fun read(fileName: String): String {
        val file = File(
            context.filesDir, "$fileName.json"
        ).apply {
            if (!exists()) {
                createNewFile()
                writeBytes(new.toByteArray())
            }
        }


        return file.readText()
    }

    override fun write(fileName: String, json: String) {
        val file = File(
            context.filesDir, "$fileName.json"
        ).apply {
            if (!exists()) {
                createNewFile()
                writeBytes(new.toByteArray())
            }
        }
        return file.writeText(json)
    }
}
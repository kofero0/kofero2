package ro.kofe.provider

import android.content.Context
import com.google.gson.Gson
import ro.kofe.model.Copy
import ro.kofe.presenter.provider.AuthDiskAccessor
import ro.kofe.presenter.provider.DiskAccessor
import java.io.File

class CopyProviderDiskAccessor(context: Context, gson:Gson): DiskAccessorImpl(context, gson.toJson(Copy("","","")))

open class DiskAccessorImpl(private val context: Context, private val new:String = "[]") : DiskAccessor, AuthDiskAccessor {
    override fun exists(url: String): Boolean {
        val file = File(context.filesDir, url)
        return file.exists()
    }

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

    override fun read(): String {
        val file = File(context.filesDir, "auth").apply {
            if(!exists()){
                createNewFile()
                writeText("")
            }
        }
        return file.readText()
    }

    override fun save(token: String) {
        val file = File(context.filesDir, "auth").apply {
            if(!exists()){
                createNewFile()
            }
            writeText(token)
        }
    }
}
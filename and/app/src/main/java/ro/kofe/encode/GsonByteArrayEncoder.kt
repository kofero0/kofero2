package ro.kofe.encode

import com.google.gson.Gson

class GsonByteArrayEncoder(private val gson: Gson): Encoder<Any, ByteArray> {
    override fun encode(value: Any): ByteArray {
        return gson.toJson(value).toByteArray()
    }
}
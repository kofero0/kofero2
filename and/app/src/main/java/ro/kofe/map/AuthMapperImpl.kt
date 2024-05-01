package ro.kofe.map

import com.google.gson.Gson
import ro.kofe.model.response.RegisterAuthResponse
import ro.kofe.presenter.provider.AuthMapper

class AuthMapperImpl(private val gson: Gson) : AuthMapper {
    override fun getAuthToken(jsonString: String) =
        gson.fromJson(jsonString, RegisterAuthResponse::class.java).token
}
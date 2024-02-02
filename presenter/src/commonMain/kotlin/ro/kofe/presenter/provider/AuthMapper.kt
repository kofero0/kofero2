package ro.kofe.presenter.provider

interface AuthMapper {
    fun getAuthToken(jsonString: String): String
}
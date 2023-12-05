package ro.kofe.provider

import android.provider.Settings

interface IdentityProvider {
    fun getDeviceId(): String
}

class IdentityProviderImpl : IdentityProvider {
    override fun getDeviceId() = Settings.Secure.ANDROID_ID
}
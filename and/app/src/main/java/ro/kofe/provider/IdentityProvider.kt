package ro.kofe.provider

import android.provider.Settings
import ro.kofe.presenter.provider.IdentityProvider

class IdentityProviderImpl : IdentityProvider {
    override fun getDeviceId() = Settings.Secure.ANDROID_ID
}
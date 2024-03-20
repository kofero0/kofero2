package ro.kofe.provider

import android.content.Context
import android.util.Log
import com.google.firebase.analytics.FirebaseAnalytics
import com.google.firebase.analytics.logEvent
import ro.kofe.model.logging.Level
import ro.kofe.presenter.provider.LoggingProvider

class ReleaseLoggingProvider(context:Context): LoggingProvider {
    private val firebaseAnalytics = FirebaseAnalytics.getInstance(context)

    override fun log(level: Level, logTag: String, message: String) {
        when (level) {
            Level.ALERT -> {
                Log.e(logTag, message)
                firebaseAnalytics.logEvent(logTag) {
                    param("message", message)
                }
            }
            Level.DEBUG -> { /*NOOP*/
            }
        }
    }
}
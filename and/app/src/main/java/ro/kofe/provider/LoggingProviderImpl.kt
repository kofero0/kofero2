package ro.kofe.provider

import android.util.Log
import ro.kofe.model.logging.Level
import ro.kofe.presenter.provider.LoggingProvider

class LoggingProviderImpl: LoggingProvider {
    override fun log(level: Level, logTag: String, message: String) {
        when(level){
            Level.DEBUG -> Log.v(logTag,message)
            Level.ALERT -> Log.e(logTag,message)
        }
    }
}
package ro.kofe.presenter

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.Dispatchers

actual object DispatcherProvider {
    actual val default: CoroutineDispatcher
        get() = Dispatchers.Default
    actual val ui: CoroutineDispatcher
        get() = Dispatchers.Main
}
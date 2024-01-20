package ro.kofe.presenter

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.Dispatchers

@Suppress("EXPECT_ACTUAL_CLASSIFIERS_ARE_IN_BETA_WARNING")
actual object DispatcherProvider {
    actual val default: CoroutineDispatcher
        get() = Dispatchers.Default
    actual val ui: CoroutineDispatcher
        get() = Dispatchers.Main
}
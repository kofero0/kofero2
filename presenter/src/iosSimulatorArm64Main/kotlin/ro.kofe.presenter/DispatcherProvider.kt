package ro.kofe.presenter

import kotlinx.coroutines.*
import platform.darwin.dispatch_async
import platform.darwin.dispatch_get_main_queue
import kotlin.coroutines.CoroutineContext

@DelicateCoroutinesApi
@OptIn(ExperimentalCoroutinesApi::class)
@Suppress("EXPECT_ACTUAL_CLASSIFIERS_ARE_IN_BETA_WARNING")
actual object DispatcherProvider {
    actual val default: CoroutineDispatcher
        get() = newSingleThreadContext("default")
    actual val ui: CoroutineDispatcher
        get() = object : CoroutineDispatcher() {
            override fun dispatch(context: CoroutineContext, block: Runnable) {
                dispatch_async(dispatch_get_main_queue()) { block.run() }
            }
        }
}
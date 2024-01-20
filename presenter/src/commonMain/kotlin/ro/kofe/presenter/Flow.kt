package ro.kofe.presenter

import kotlinx.coroutines.*
import kotlinx.coroutines.flow.Flow

interface Cancellable {
    fun cancel()
}

fun <T> Flow<T>.collect(onEach: (T) -> Unit, onCompletion: (cause: Throwable?) -> Unit): Cancellable {
    val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main)

    scope.launch {
        try {
            collect {
                onEach(it)
            }

            onCompletion(null)
        } catch (e: Throwable) {
            onCompletion(e)
        }
    }

    return object : Cancellable {
        override fun cancel() {
            scope.cancel()
        }
    }
}
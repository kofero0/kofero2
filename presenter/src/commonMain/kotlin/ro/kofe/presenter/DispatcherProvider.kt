package ro.kofe.presenter

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.DelicateCoroutinesApi

@DelicateCoroutinesApi
expect object DispatcherProvider {
    val default: CoroutineDispatcher
    val ui: CoroutineDispatcher
}
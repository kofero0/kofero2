package ro.kofe.presenter

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.DelicateCoroutinesApi

@Suppress("EXPECT_ACTUAL_CLASSIFIERS_ARE_IN_BETA_WARNING")
@DelicateCoroutinesApi
expect object DispatcherProvider {
    val default: CoroutineDispatcher
    val ui: CoroutineDispatcher
}
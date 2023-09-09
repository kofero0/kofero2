package ro.kofe.view

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.presenter.ipv.Interactor
import ro.kofe.presenter.ipv.KView

abstract class KViewModel(private val interactor: Interactor<out KView>) : ViewModel(), KView {
    private val _exception = MutableStateFlow<Exception?>(null)
    val exception = _exception.asStateFlow()

    override fun error(e: Exception) = _exception.update {
        e
    }

    fun onStart() = interactor.viewResumed()
    fun onStop() = interactor.viewPaused()
}
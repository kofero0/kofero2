package ro.kofe.view

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import ro.kofe.model.Character
import ro.kofe.presenter.ipv.acknowledgment.AckInteractor
import ro.kofe.presenter.ipv.acknowledgment.AckKView
import javax.inject.Inject

class AckViewModel @Inject constructor(private val interactor: AckInteractor): KViewModel(interactor), AckKView {
    init {
        interactor.setView(this)
    }


    private val _ackCopy = MutableStateFlow("")
    val ackCopy = _ackCopy.asStateFlow()

    private val _error = MutableStateFlow<Exception?>(null)
    val error = _error.asStateFlow()

    override fun error(e: Exception) = _error.update { e }

    override fun display(copy: String) = _ackCopy.update { copy }
}
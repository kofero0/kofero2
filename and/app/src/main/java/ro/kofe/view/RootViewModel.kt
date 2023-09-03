package ro.kofe.view

import androidx.lifecycle.ViewModel
import dagger.hilt.android.lifecycle.HiltViewModel
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootKView
import javax.inject.Inject

@HiltViewModel
class RootViewModel @Inject constructor(private val interactor: RootInteractor) : ViewModel(),
    RootKView {
    init {
        interactor.setView(this)
    }

    fun onStart() {
        interactor.viewResumed()
    }

    fun onStop() {
        interactor.viewPaused()
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }
}
package ro.kofe.view

import ro.kofe.presenter.ipv.about.AboutInteractor
import ro.kofe.presenter.ipv.about.AboutKView
import javax.inject.Inject

class AboutViewModel @Inject constructor(private val interactor: AboutInteractor): KViewModel(interactor), AboutKView {
    init {
        interactor.setView(this)
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }

}
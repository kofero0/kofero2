package ro.kofe.view

import androidx.lifecycle.ViewModel
import dagger.hilt.android.lifecycle.HiltViewModel
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootKView
import javax.inject.Inject

@HiltViewModel
class RootViewModel @Inject constructor(interactor: RootInteractor) : KViewModel(interactor),
    RootKView {
}
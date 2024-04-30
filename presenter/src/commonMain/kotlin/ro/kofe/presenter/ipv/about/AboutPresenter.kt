package ro.kofe.presenter.ipv.about

import ro.kofe.model.logging.LogTag.ABOUT_PRESENTER
import ro.kofe.presenter.ipv.Presenter
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.CopyProvider
import ro.kofe.presenter.provider.LoggingProvider

interface AboutPresenter: Presenter<AboutKView>

class AboutPresenterImpl(loggingProvider: LoggingProvider, private val copyProvider: CopyProvider): AboutPresenter, PresenterImpl<AboutKView>(
    loggingProvider = loggingProvider, logTag = ABOUT_PRESENTER
){

}
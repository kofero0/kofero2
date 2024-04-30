package ro.kofe.presenter.ipv.acknowledgment

import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import ro.kofe.model.ProviderError
import ro.kofe.model.logging.LogTag.ACK_PRESENTER
import ro.kofe.presenter.ipv.Presenter
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.CopyProvider
import ro.kofe.presenter.provider.LoggingProvider


interface AckPresenter: Presenter<AckKView> {
    suspend fun showAck(): Flow<ProviderError>
}

class AckPresenterImpl(loggingProvider: LoggingProvider, private val copyProvider: CopyProvider) : AckPresenter,
    PresenterImpl<AckKView>(loggingProvider = loggingProvider, logTag = ACK_PRESENTER) {
    override suspend fun showAck() = flow<ProviderError> {
        copyProvider.get().map { view?.display(it.acknowledgment) }
    }
}
package ro.kofe.presenter.ipv.root

import kotlinx.coroutines.flow.Flow
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface RootPresenter : Presenter<RootKView> {
    suspend fun checkVersion(): Flow<ProviderError>
}
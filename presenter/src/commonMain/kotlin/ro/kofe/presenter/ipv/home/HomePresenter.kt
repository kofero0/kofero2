package ro.kofe.presenter.ipv.home

import arrow.core.Either
import ro.kofe.model.ProviderError
import ro.kofe.presenter.ipv.Presenter

interface HomePresenter : Presenter<HomeView> {
    suspend fun showGames(): Either<ProviderError, Unit>
    suspend fun showFavs(): Either<ProviderError, Unit>
}
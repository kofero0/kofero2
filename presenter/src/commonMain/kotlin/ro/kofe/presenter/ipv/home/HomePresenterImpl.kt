package ro.kofe.presenter.ipv.home

import arrow.core.raise.either
import ro.kofe.model.*
import ro.kofe.model.logging.LogTag.HOME_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider


class HomePresenterImpl(
    private var gameProvider: Provider<Game>,
    private var imageProvider: ImageProvider,
    private var favoritesProvider: FavoritesProvider,
    loggingProvider: LoggingProvider
) : HomePresenter, PresenterImpl<HomeKView>(
    null, loggingProvider, HOME_PRESENTER
) {

    override fun setView(view: HomeKView) {
        this.view = view
    }

    override suspend fun showGames() = either<ProviderError, Unit> {
        gameProvider.get(ArrayList()).map { games ->
            view?.displayGames(games)
            displayImages(games)
        }
    }

    override suspend fun showFavs() = either<ProviderError, Unit> {
        favoritesProvider.get(ArrayList()).map { objs ->
            view?.displayFavs(objs)
            displayImages(objs)
        }
    }

    private suspend fun displayImages(objs: List<Obj>) = either {
        for (obj in objs) {
            when (obj) {
                is Character -> getImage(obj.iconUrl)
                is Game -> getImage(obj.iconUrl)
                else -> raise(InvalidObject(obj.uid))
            }
        }
    }


    private suspend fun getImage(iconUrl: String) =
        imageProvider.get(iconUrl).map { image -> view?.display(iconUrl, image) }

    override fun shutdown() {
        view = null
    }
}
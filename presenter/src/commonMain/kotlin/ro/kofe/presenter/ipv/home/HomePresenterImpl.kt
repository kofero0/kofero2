package ro.kofe.presenter.ipv.home

import arrow.core.raise.either
import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.model.InvalidObject
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

    override suspend fun showGames() = flow {
        gameProvider.get(ArrayList()).collect { either ->
            either.fold({ e ->
                view?.displayGamesError(e)
                emit(e)
            }) { games ->
                view?.displayGames(games)
                displayImages(games).onLeft { emit(it) }
            }
        }
    }

    override suspend fun showFavs() = flow {
        favoritesProvider.get().fold({ e ->
            view?.displayFavsError(e)
            emit(e)
        }) { favs ->
            view?.displayFavs(favs)
            displayImages(favs).onLeft { emit(it) }
        }
    }

    private suspend fun displayImages(objs: List<Any>) = either {
        for (obj in objs) {
            when (obj) {
                is Favorite -> obj.character?.also { getImage(it.iconUrl) } ?: run {
                    getImage(obj.game.iconUrl)
                }

                is Game -> getImage(obj.iconUrl)
                else -> raise(InvalidObject(999))
            }
        }
    }

    private suspend fun getImage(iconUrl: String) =
        imageProvider.get(iconUrl).map { image -> view?.display(iconUrl, image) }

    override fun shutdown() {
        view = null
    }
}
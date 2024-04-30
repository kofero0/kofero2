package ro.kofe.presenter.ipv.home

import arrow.core.raise.either
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import ro.kofe.model.*
import ro.kofe.model.logging.LogTag.HOME_PRESENTER
import ro.kofe.presenter.ipv.Presenter
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.*

interface HomePresenter : Presenter<HomeKView> {
    suspend fun showGames(): Flow<ProviderError>
    suspend fun showFavs(): Flow<ProviderError>
    suspend fun showCopy(): Flow<ProviderError>
}

class HomePresenterImpl(
    private var copyProvider: CopyProvider,
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

    override suspend fun showCopy() = flow {
        copyProvider.get().fold({ e ->
            emit(e)
        }) {
            view?.displayCopy(it)
        }
    }

    private suspend fun displayImages(objs: List<Any>) = either {
        suspend fun getImage(iconUrl: String) =
            imageProvider.get(iconUrl).map { image -> view?.display(iconUrl, image) }

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


    override fun shutdown() {
        view = null
    }
}
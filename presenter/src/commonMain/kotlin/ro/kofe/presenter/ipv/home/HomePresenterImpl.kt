package ro.kofe.presenter.ipv.home

import arrow.core.raise.either
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.flow.flow
import ro.kofe.model.Character
import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.model.InvalidObject
import ro.kofe.model.Obj
import ro.kofe.model.logging.LogTag.HOME_PRESENTER
import ro.kofe.presenter.ipv.PresenterImpl
import ro.kofe.presenter.provider.FavoritesProvider
import ro.kofe.presenter.provider.ImageProvider
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.provider.Provider


class HomePresenterImpl(
    private var gameProvider: Provider<Game>,
    private var charProvider: Provider<Character>,
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
            val gameUids = ArrayList<Int>()
            val charUids = ArrayList<Int>()
            for (fav in favs) {
                if (fav.type == Favorite.Type.GAME) {
                    gameUids.add(fav.uid)
                }
                if (fav.type == Favorite.Type.CHAR) {
                    charUids.add(fav.uid)
                }
            }
            gameProvider.get(gameUids).collect { gameEither ->
                gameEither.fold({
                    view?.displayFavsError(it)
                }) { games ->
                    val objs = ArrayList<Obj>()
                    for(game in games){
                        if(gameUids.contains(game.uid)){
                            objs.add(game)
                        }
                    }
                    if(charUids.size > 0){
                        charProvider.get(charUids).collect { charEither ->
                            charEither.fold({
                                view?.displayFavsError(it)
                            }) { chars ->
                                objs.addAll(chars)
                                view?.displayFavs(objs)
                                displayImages(objs).onLeft { emit(it) }
                            }
                        }
                    }
                    else{
                        view?.displayFavs(objs)
                    }
                }
            }
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
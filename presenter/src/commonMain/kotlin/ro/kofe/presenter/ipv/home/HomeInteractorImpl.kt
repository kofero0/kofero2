package ro.kofe.presenter.ipv.home

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch
import ro.kofe.model.*
import ro.kofe.model.Event.Value.BUTTON_PRESSED
import ro.kofe.model.Event.ViewTag.GAME_VIEW
import ro.kofe.model.Event.ViewTag.HOME_VIEW
import ro.kofe.model.Event.ViewTag.CHAR_VIEW
import ro.kofe.model.logging.Level
import ro.kofe.model.logging.LogTag.HOME_INTERACTOR
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.millisNow
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import kotlin.coroutines.CoroutineContext

class HomeInteractorImpl(
    presenter: HomePresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    loggingProvider: LoggingProvider,
    router: HomeRouter,
    private val context: CoroutineContext
) : HomeInteractor, InteractorImpl<HomeKView, HomePresenter>(
    presenter,
    stateLogger,
    stateReducer,
    router,
    loggingProvider,
    HOME_INTERACTOR
) {

    override suspend fun favPressed(obj: Obj) {
        stateLogger.logState(
            millisNow(),
            Event(HOME_VIEW, BUTTON_PRESSED, HashMap<String,Any>().apply { this[BUTTON_PRESSED.name] = obj.uid })
        )
        val tag = when(obj){
            is Game -> { GAME_VIEW }
            is Character -> { CHAR_VIEW }
            else -> {
                log(Level.ALERT, "object $obj is not a valid favorite")
                return
            }
        }
        router.routeTo(tag,obj.uid)
    }

    override suspend fun gamePressed(game: Game) {
        stateLogger.logState(
            millisNow(),
            Event(HOME_VIEW, BUTTON_PRESSED, HashMap<String, Any>().apply { this[BUTTON_PRESSED.name] = game.uid })
        )
        router.routeTo(GAME_VIEW, game.uid)
    }

    override fun viewResumed() {
        super.viewResumed()
        CoroutineScope(context).launch {
            presenter.showGames().onLeft {
                view?.displayGamesError(it)
                log(Level.ALERT,"provider error showing games! $it")
            }
            presenter.showFavs().onLeft {
                view?.displayFavsError(it)
                log(Level.ALERT, "provider error showing favs! $it")
            }
        }
    }
}
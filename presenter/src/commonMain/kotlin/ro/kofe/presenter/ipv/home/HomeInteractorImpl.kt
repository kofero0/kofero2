package ro.kofe.presenter.ipv.home

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch
import ro.kofe.model.Event
import ro.kofe.model.Event.Value.BUTTON_PRESSED
import ro.kofe.model.Favorite
import ro.kofe.model.Game
import ro.kofe.model.HttpError
import ro.kofe.model.ViewTag.HOME_VIEW
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
    private val context: CoroutineContext
) : HomeInteractor, InteractorImpl<HomeKView, HomePresenter>(
    presenter, stateLogger, stateReducer, loggingProvider, HOME_INTERACTOR
) {

    override suspend fun favPressed(fav: Favorite) {
        stateLogger.logState(
            millisNow(),
            Event(HOME_VIEW, BUTTON_PRESSED, HashMap<String, Any>().apply { this[BUTTON_PRESSED.name] = fav.game.uid })
        )
    }


    override suspend fun gamePressed(game: Game) = stateLogger.logState(
        millisNow(),
        Event(HOME_VIEW, BUTTON_PRESSED, HashMap<String, Any>().apply { this[BUTTON_PRESSED.name] = game.uid })
    )


    override fun viewResumed() = super.viewResumed().also {
            CoroutineScope(context).launch {
            presenter.showGames().collect {
                log(Level.ALERT, "provider error showing games! $it")
                if (it is HttpError) {
                    log(Level.ALERT, "response: ${it.response}")
                    log(Level.ALERT, "statusCode: ${it.statusCode}")
                }
            }
            presenter.showFavs().collect {
                log(Level.ALERT, "provider error showing favs! $it")
                if (it is HttpError) {
                    log(Level.ALERT, "response: ${it.response}")
                    log(Level.ALERT, "statusCode: ${it.statusCode}")
                }
            }
            presenter.showCopy().collect {
                log(Level.ALERT, "provider error showing copy! $it")
                if (it is HttpError) {
                    log(Level.ALERT, "response: ${it.response}")
                    log(Level.ALERT, "statusCode: ${it.statusCode}")
                }
            }
        }
    }
}
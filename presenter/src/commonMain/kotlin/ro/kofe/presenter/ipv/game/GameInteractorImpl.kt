package ro.kofe.presenter.ipv.game

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.FlowCollector
import kotlinx.coroutines.launch
import ro.kofe.model.Character
import ro.kofe.model.Event
import ro.kofe.model.Event.Value.BUTTON_PRESSED
import ro.kofe.model.HttpError
import ro.kofe.model.ProviderError
import ro.kofe.model.ViewTag.CHAR_VIEW
import ro.kofe.model.ViewTag.GAME_VIEW
import ro.kofe.model.logging.Level
import ro.kofe.model.logging.LogTag.GAME_INTERACTOR
import ro.kofe.presenter.ipv.InteractorImpl
import ro.kofe.presenter.millisNow
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import kotlin.coroutines.CoroutineContext

class GameInteractorImpl(
    presenter: GamePresenter,
    stateLogger: StateLogger,
    stateReducer: StateReducer,
    private val loggingProvider: LoggingProvider,
    private val context: CoroutineContext
) : GameInteractor, InteractorImpl<GameKView, GamePresenter>(
    presenter, stateLogger, stateReducer, loggingProvider, GAME_INTERACTOR
) {
    private var gameUid: Int? = null

    override fun viewResumed() = super.viewResumed().also {
        println("gameUid: $gameUid")
        println(this.toString())
        CoroutineScope(context).launch {
            gameUid?.let { uid ->
                loggingProvider.log(Level.DEBUG, GAME_INTERACTOR, "gameUid: $uid")
                presenter.showGame(uid).collect { logProviderError(it) }
            }
        }
    }

    override suspend fun charPressed(char: Character) =
        stateLogger.logState(
            millisNow(),
            Event(GAME_VIEW, BUTTON_PRESSED, HashMap<String, Any>().apply {
                this[BUTTON_PRESSED.name] = char.uid
            })
        )


    override suspend fun setGameUid(uid: Int) {
        println("gameUid set: $uid")
        println(this.toString())
        this.gameUid = uid
    }

    private fun logProviderError(error: ProviderError) {
        loggingProvider.log(Level.ALERT, GAME_INTERACTOR, "provider error: $error")
        if(error is HttpError){
            loggingProvider.log(Level.ALERT, GAME_INTERACTOR, error.response)
            loggingProvider.log(Level.ALERT, GAME_INTERACTOR, "${error.statusCode}")
        }
    }
}
package ro.kofe.presenter.state

import ro.kofe.model.Event

interface StateLogger {
    fun logState(unixTime: Long, event: Event)
    fun getStateMap(): Map<Long, Event>
}
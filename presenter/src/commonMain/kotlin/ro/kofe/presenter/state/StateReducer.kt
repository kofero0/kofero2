package ro.kofe.presenter.state

import ro.kofe.model.Event

interface StateReducer {
    fun reduce(stateMap: Map<Long, Event>): Event
    fun authorize(event: Event, stateMap: Map<Long, Event>): Boolean
}
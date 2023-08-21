package ro.kofe.presenter.state

import ro.kofe.model.Event

interface StateReducer {
    suspend fun reduce(stateMap: Map<Long, Event>): Event
    suspend fun authorize(event: Event, stateMap: Map<Long, Event>): Boolean
}
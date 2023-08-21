package ro.kofe.presenter.state

import ro.kofe.model.Event

class StateReducerImpl: StateReducer {
    override suspend fun reduce(stateMap: Map<Long, Event>): Event {
        return Event(Event.ViewTag.CHAR_VIEW,Event.Value.VIEW_ENTERED,HashMap())
    }

    override suspend fun authorize(event: Event, stateMap: Map<Long, Event>): Boolean {
        return true
    }
}
package ro.kofe.presenter.state

import arrow.core.Either
import ro.kofe.model.Event
import ro.kofe.model.ProviderError

interface StateProvider {
    fun get(): Either<ProviderError, Map<Long,Event>>
    fun save(map: Map<Long, Event>): Either<ProviderError, Unit>
}
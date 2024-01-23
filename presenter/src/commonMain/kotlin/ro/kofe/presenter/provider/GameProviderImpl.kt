package ro.kofe.presenter.provider

import io.ktor.client.*
import ro.kofe.model.Game
import ro.kofe.presenter.map.Mapper

class GameProviderImpl(
    client: HttpClient,
    jsonFilename: String,
    urlPrefix: String,
    mapper: Mapper<List<Game>, String>,
    requestMapper: Mapper<List<Int>,String>,
    diskAccessor: DiskAccessor
) : ProviderAbstract<Game>(client, jsonFilename, urlPrefix, mapper, requestMapper, diskAccessor) {
    override fun isEqual(element: Game, id: Int) = element.uid == id

    override fun isEqual(one: Game, two: Game) = isEqual(one, two.uid)
}
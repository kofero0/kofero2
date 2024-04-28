package ro.kofe.presenter.provider

import io.ktor.client.*
import ro.kofe.model.Move
import ro.kofe.presenter.map.Mapper

class MoveProviderImpl(
    client: HttpClient,
    jsonFilename: String,
    urlPrefix: String,
    mapper: Mapper<List<Move>, String>,
    queryMapper: Mapper<List<String>, String>,
    requestMapper: Mapper<List<Int>,String>,
    diskAccessor: DiskAccessor
) : ProviderAbstract<Move>(client, jsonFilename, urlPrefix, mapper, requestMapper, queryMapper, diskAccessor) {
    override fun isEqual(element: Move, id: Int) = element.uid == id

    override fun isEqual(one: Move, two: Move) = isEqual(one, two.uid)
}
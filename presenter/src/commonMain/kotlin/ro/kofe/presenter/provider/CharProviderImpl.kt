package ro.kofe.presenter.provider

import io.ktor.client.*
import ro.kofe.model.Character
import ro.kofe.presenter.map.Mapper

class CharProviderImpl(
    client: HttpClient,
    jsonFilename: String,
    urlPrefix: String,
    mapper: Mapper<List<Character>, String>,
    queryMapper: Mapper<List<String>,String>,
    requestMapper: Mapper<List<Int>,String>,
    diskAccessor: DiskAccessor
) : ProviderAbstract<Character>(client, jsonFilename, urlPrefix, mapper, requestMapper, queryMapper ,diskAccessor) {
    override fun isEqual(element: Character, id: Int) = element.uid == id

    override fun isEqual(one: Character, two: Character) = isEqual(one, two.uid)
}
package ro.kofe.model

sealed interface Error

sealed class ProviderError: Error

class FileReadError(val filePath:String): ProviderError()
class IdsNotFound(val ids:List<Int>): ProviderError()
class IncorrectCount(val ids:List<Int>): ProviderError()
class InvalidObject(val id:Int): ProviderError()

sealed class NetworkError: ProviderError()

class Http(val statusCode: Int, val response: String): NetworkError()
object NoPermission : NetworkError()
object Hardware: NetworkError()
object Other: NetworkError()

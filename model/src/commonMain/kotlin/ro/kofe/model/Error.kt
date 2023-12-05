package ro.kofe.model

sealed interface Error

sealed class ProviderError : Error

class FileReadError(val filePath: String) : ProviderError()
class IdsNotFound(val ids: List<Int>) : ProviderError()
class IncorrectCount(val ids: List<Int>) : ProviderError()
class InvalidObject(val id: Int) : ProviderError()
class CombinedError(val e1: Error, val e2: Error) : ProviderError()

sealed class NetworkError : ProviderError()

class HttpError(val statusCode: Int, val response: String) : NetworkError()
object NoPermissionError : NetworkError()
object HardwareError : NetworkError()
object OtherError : NetworkError()

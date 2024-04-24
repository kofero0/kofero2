package ro.kofe.model

data class Game(
    val uid: Int,
    val name: String,
    val searchTerms: List<String>,
    val version:String,
    val date: Long,
    val charIds: List<Int>,
    val iconUrl: String
)
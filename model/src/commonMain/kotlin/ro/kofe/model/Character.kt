package ro.kofe.model

data class Character(
    val uid: Int, val name: String, val attributes: Map<String, String>, val moveIds: List<Int>, val iconUrl: String
)

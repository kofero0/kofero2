package ro.kofe.model

data class Event(val view: ViewTag, val value: Value, val extras: Map<String, Any>) {
    enum class Value {
        VIEW_ENTERED,
        VIEW_EXITED,
        BUTTON_PRESSED,
        ROUTING_REQUEST,
        ROUTING_DENIED
    }

    object ExtraKey {
        const val DESTINATION_VIEW = "destview"
        const val GAME_ID = "gameid"
    }
}

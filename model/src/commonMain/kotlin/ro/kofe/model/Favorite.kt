package ro.kofe.model

data class Favorite(val uid:Int, val type:Type){
    enum class Type{
        GAME,
        CHAR
    }
}

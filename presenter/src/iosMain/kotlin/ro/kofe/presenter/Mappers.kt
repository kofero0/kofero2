package ro.kofe.presenter

import ro.kofe.model.*
import ro.kofe.presenter.map.Mapper


abstract class GameMapper: Mapper<List<Game>, String>{
    abstract override fun mapLeft(data: String): List<Game>
    abstract override fun mapRight(data: List<Game>): String
}
abstract class CharMapper: Mapper<List<Character>, String>{
    abstract override fun mapLeft(data: String): List<Character>
    abstract override fun mapRight(data: List<Character>): String
}
abstract class MoveMapper: Mapper<List<Move>, String> {
    abstract override fun mapLeft(data: String): List<Move>
    abstract override fun mapRight(data: List<Move>): String
}
abstract class RequestMapper: Mapper<List<Int>, String> {
    abstract override fun mapLeft(data: String): List<Int>
    abstract override fun mapRight(data: List<Int>): String
}
abstract class StatusMapper: Mapper<Status, String> {
    abstract override fun mapLeft(data: String): Status
    abstract override fun mapRight(data: Status): String
}

abstract class CopyMapper: Mapper<Copy, String> {
    abstract override fun mapLeft(data: String): Copy
    abstract override fun mapRight(data: Copy): String
}
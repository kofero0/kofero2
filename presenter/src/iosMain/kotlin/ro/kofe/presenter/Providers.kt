package ro.kofe.presenter

import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.Move
import ro.kofe.presenter.provider.Provider

interface GameProvider : Provider<Game>
interface CharacterProvider : Provider<Character>
interface MoveProvider : Provider<Move>
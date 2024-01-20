package ro.kofe.state

import android.content.Context
import ro.kofe.model.Event
import ro.kofe.presenter.map.Mapper
import ro.kofe.presenter.state.StateLogger
import java.io.File

class StateLoggerImpl(context: Context, private val mapper: Mapper<Map<Long, Event>, ByteArray>) :
    StateLogger {
    private val file: File by lazy {
        File(context.filesDir, "state").apply {
            if (!exists()) createNewFile()
            writeBytes("[]".toByteArray())
        }
    }

    override fun getStateMap() = mapper.mapLeft(file.readBytes())

    override fun logState(unixTime: Long, event: Event) =
        file.writeBytes(mapper.mapRight(HashMap(getStateMap()).apply { put(unixTime, event) }))

}
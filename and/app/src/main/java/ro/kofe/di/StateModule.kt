package ro.kofe.di

import android.content.Context
import com.google.gson.Gson
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.components.ActivityComponent
import dagger.hilt.android.qualifiers.ApplicationContext
import ro.kofe.map.Mapper
import ro.kofe.map.StateMapMapper
import ro.kofe.model.Event
import ro.kofe.presenter.state.StateLogger
import ro.kofe.presenter.state.StateReducer
import ro.kofe.presenter.state.StateReducerImpl
import ro.kofe.state.StateLoggerImpl

@Module
@InstallIn(ActivityComponent::class)
object StateModule {
    @Provides
    fun provideStateMapMapper(gson: Gson): Mapper<Map<Long, Event>, ByteArray> {
        return StateMapMapper(gson)
    }

    @Provides
    fun provideStateLogger(
        @ApplicationContext context: Context,
        mapper: Mapper<Map<Long, Event>, ByteArray>
        ): StateLogger {
        return StateLoggerImpl(context,mapper)
    }

    @Provides
    fun provideStateReducer(
    ): StateReducer {
        return StateReducerImpl()
    }
}
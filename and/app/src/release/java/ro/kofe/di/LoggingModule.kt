package ro.kofe.di

import android.content.Context
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import ro.kofe.presenter.provider.LoggingProvider
import ro.kofe.provider.ReleaseLoggingProvider


@Module
@InstallIn(SingletonComponent::class)
object LoggingModule {
    @Provides
    fun provideLoggingProvider(@ApplicationContext context: Context): LoggingProvider = ReleaseLoggingProvider(context)
}
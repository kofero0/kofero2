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
object EndpointModule {
    @Provides
    @RootModule.UrlPrefix
    fun provideUrlPrefix(): String = "https://kofero.org"
}
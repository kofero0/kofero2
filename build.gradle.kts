buildscript {
    repositories {
        mavenCentral()
    }
    dependencies {
        classpath("com.google.dagger:hilt-android-gradle-plugin:2.47")
    }
}

subprojects{
    group = "ro.kofe"
    version = "0.0.018"
}

plugins {
    kotlin("multiplatform") version "1.8.10" apply false
    id("com.android.application") version "7.4.0" apply false
    id("com.android.library") version "7.4.0" apply false
    id("org.jetbrains.kotlin.android") version "1.8.10" apply false
}
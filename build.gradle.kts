buildscript {
    repositories {
        mavenCentral()
    }
    dependencies {
        classpath("com.google.dagger:hilt-android-gradle-plugin:2.47")
    }
}

subprojects {
    group = "ro.kofe"
    version = "0.0.023"
}

plugins {
    kotlin("multiplatform") version "1.9.20" apply false
    id("com.android.application") version "8.3.1" apply false
    id("com.android.library") version "8.3.1" apply false
    id("org.jetbrains.kotlin.android") version "1.9.20" apply false
    id("com.google.gms.google-services") version "4.3.14" apply false
    id("com.google.firebase.crashlytics") version "2.9.9" apply false
}
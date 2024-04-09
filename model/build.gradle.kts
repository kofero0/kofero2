plugins {
    kotlin("multiplatform")
    kotlin("plugin.serialization") version "1.8.22"
}

repositories {
    mavenCentral()
}

kotlin {
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(JavaVersion.VERSION_17.toString()))
    }

    jvm {
        compilations.all {
            kotlinOptions.jvmTarget = JavaVersion.VERSION_17.toString()
        }
        withJava()
        testRuns["test"].executionTask.configure {
            useJUnitPlatform()
        }
    }
    iosX64()
    iosArm64()
    iosSimulatorArm64()


    sourceSets {
        commonMain
    }
}

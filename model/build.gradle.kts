plugins {
    kotlin("multiplatform") version "1.8.21"
    id("maven-publish")
}

group = "ro.kofe"
version = "0.0.015"

repositories {
    mavenCentral()
}

kotlin {
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(JavaVersion.VERSION_11.toString()))
    }

    jvm {
        compilations.all {
            kotlinOptions.jvmTarget = JavaVersion.VERSION_11.toString()
        }
        withJava()
        testRuns["test"].executionTask.configure {
            useJUnitPlatform()
        }
    }
    iosArm64("iosA64")
    iosX64("iosX64")


    sourceSets {
        commonMain
    }
}

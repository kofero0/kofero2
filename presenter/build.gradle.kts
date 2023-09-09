import org.jetbrains.kotlin.gradle.plugin.mpp.Framework.BitcodeEmbeddingMode.BITCODE
import org.jetbrains.kotlin.gradle.plugin.mpp.NativeBuildType

plugins {
    kotlin("multiplatform")
    kotlin("native.cocoapods")
    id("maven-publish")
}

group = "ro.kofe"
version = "0.0.018"
val frameworkName = "presenter"

kotlin {
    cocoapods {
        summary = "Shared code artifact for kofero-ios"
        homepage = "http://kofe.ro"
        name = frameworkName

        framework {
            baseName = frameworkName
            isStatic = false
            transitiveExport = true
            embedBitcode(BITCODE)
        }

        xcodeConfigurationToNativeBuildType["CUSTOM_DEBUG"] = NativeBuildType.DEBUG
        xcodeConfigurationToNativeBuildType["CUSTOM_RELEASE"] = NativeBuildType.RELEASE
    }

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
    ios("ios")


    targets {
        iosArm64("iosArm64") {
            binaries.framework {
                embedBitcode(BITCODE)
                baseName = frameworkName + "Base"
            }
        }
        iosX64("iosX64") {
            binaries.framework {
                embedBitcode(BITCODE)
                baseName = frameworkName + "Base"
            }
        }
    }


    sourceSets {
        commonMain {
            dependencies {
                implementation(project(":model"))
                implementation("com.soywiz.korlibs.klock:klock:2.4.13")
                implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.7.3")
                implementation("io.arrow-kt:arrow-core:1.2.0")
            }
        }
        commonTest {
            dependencies {
                implementation(kotlin("test"))
            }
        }
        val iosMain by getting {
            dependencies {
                commonMain
            }
        }
        val jvmMain by getting {
            dependencies {
                commonMain
            }
        }
    }
}
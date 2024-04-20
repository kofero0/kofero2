plugins {
    kotlin("jvm")
}

group = "org.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
    mavenLocal()
}

dependencies {
    testImplementation("org.jetbrains.kotlin:kotlin-test")

    //implementation("ro.kofe:model:0.0.031")
    implementation("com.google.code.gson:gson:2.8.9")
}

tasks.test {
    useJUnitPlatform()
}
kotlin {
    jvmToolchain(11)
}
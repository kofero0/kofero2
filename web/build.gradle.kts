import org.jetbrains.kotlin.gradle.tasks.KotlinCompile
import java.io.FileOutputStream
import java.util.Properties


plugins {
	id("org.springframework.boot") version "2.7.14"
	id("io.spring.dependency-management") version "1.1.2"
	kotlin("jvm")
	kotlin("plugin.spring") version "1.8.22"
}

val generatedVersionDir = "$buildDir/generated-version"

sourceSets {
	main {
		kotlin {
			output.dir(generatedVersionDir)
		}
	}
}

tasks.register("generateVersionProperties") {
	doLast {
		val propertiesFile = file("$generatedVersionDir/version.properties")
		propertiesFile.parentFile.mkdirs()
		val properties = Properties()
		properties.setProperty("version", "$version")
		val out = FileOutputStream(propertiesFile)
		properties.store(out, null)
	}
}

tasks.named("processResources") {
	dependsOn("generateVersionProperties")
}



java.sourceCompatibility = JavaVersion.VERSION_11

configurations {
	compileOnly {
		extendsFrom(configurations.annotationProcessor.get())
	}
}

dependencies {
	implementation(project(":auth"))
	implementation(project(":model"))
	implementation("org.jetbrains.kotlin:kotlin-reflect")
	implementation("org.jetbrains.kotlin:kotlin-stdlib-jdk8")
	implementation("org.springframework.boot:spring-boot-starter-web")
	implementation("com.fasterxml.jackson.module:jackson-module-kotlin")
	testImplementation("org.springframework.boot:spring-boot-starter-test")
	implementation("org.springframework.boot:spring-boot-starter-data-jpa")
	developmentOnly("org.springframework.boot:spring-boot-devtools")
	runtimeOnly("com.h2database:h2")
	annotationProcessor("org.projectlombok:lombok:1.18.20")
}

tasks.withType<KotlinCompile> {
	kotlinOptions {
		freeCompilerArgs = listOf("-Xjsr305=strict")
		jvmTarget = "11"
	}
}

tasks.withType<Test> {
	useJUnitPlatform()
}

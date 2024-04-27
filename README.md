# kofero2

Kofero2 is a v2 rewrite of an unfinished Kotlin Multiplatform project updated to utilize declarative UI frameworks in
the two mobile targets and coroutines/flows+Arrow in the shared kotlin code.

Google Play: https://play.google.com/store/apps/details?id=ro.kofe.frames
App Store: Under review

## Architecture
### View
Rendering and display code that is isolated from any business logic. 
### Interactor
Handles all user and system interaction to 
### Presenter
Fetch data from providers and collate marshalled data to appropriate views
### Provider
Android Repository pattern objects that abstract REST API and disk access away from Presenter objects
### Entity (Model)
Clean POJOs.
### Router
Initially planned to be part of the shared code with presenter, Jetpack Compose is too tightly coupled to use with anything but Jetpack Navigation. An example of what a multiplatform Router pattern could look like is located in the ios codebase.
### Resolver and State
Deprecated architecture that would allow the application to resolve the last previous screen and data from a crash given a StateMap that is constantly upkept by Interactors. Current feature complexity does not warrant a full implementation at this time.

## Core Libraries

### https://arrow-kt.io/

### https://ktor.io/

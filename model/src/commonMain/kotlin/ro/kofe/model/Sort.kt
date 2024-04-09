package ro.kofe.model

enum class Sort {
    RELEASE_DATE,
    NAME;

    enum class Direction {
        ASCENDING, DESCENDING
    }
}
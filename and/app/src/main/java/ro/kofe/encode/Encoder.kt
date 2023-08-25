package ro.kofe.encode

interface Encoder<Input,Output> {
    fun encode(value:Input): Output
}


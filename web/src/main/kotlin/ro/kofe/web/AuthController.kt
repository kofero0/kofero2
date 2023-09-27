package ro.kofe.web

import org.springframework.beans.factory.annotation.Autowired
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.PutMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController
import ro.kofe.model.authDelimiter
import ro.kofe.model.authPrefix
import ro.kofe.model.request.RegisterAuthRequest
import ro.kofe.model.response.RegisterAuthResponse
import java.security.MessageDigest
import java.security.SecureRandom


@RestController
@RequestMapping("/auth")
class AuthController(
    @Autowired private val accountRepository: AccountRepository,

    @Autowired private val service: AccountIdGenerationService
) {
    private fun isBlacklisted(uid: String) = false

    @PutMapping("/register")
    fun register(@RequestBody request: RegisterAuthRequest): ResponseEntity<Any> {
        val split = request.prefixedUid.split(authDelimiter)
        if(split.size != 2 || split[0] != authPrefix || isBlacklisted(split[1])){
            return ResponseEntity(HttpStatus.UNAUTHORIZED)
        }
        accountRepository
        val salt = getSalt()
        val secret = getHash(split[1], getSalt())
        val hash = getHash(secret,salt)

        val account = Account(
            id = service.newAccountId(),
            deviceId = split[1],
            salt = salt,
            hash = hash,
            privilege = Account.Privilege.USER,
            expiration = 0L,
            status = Account.Status.VALID
        )
        accountRepository.save(account)

        return ResponseEntity(RegisterAuthResponse(System.currentTimeMillis(),"${account.id}$authDelimiter$secret") ,HttpStatus.OK)
    }

    private fun getHash(password: String, salt: ByteArray?) = StringBuilder().apply {
        val bytes: ByteArray = MessageDigest.getInstance("SHA-256").apply {
            update(salt)
        }.digest(password.toByteArray())
        for (i in bytes.indices) {
            append(((bytes[i].toInt() and 0xff) + 0x100).toString(16).substring(1))
        }
    }.toString()

    private fun getSalt() = ByteArray(16).apply { SecureRandom().nextBytes(this) }
}
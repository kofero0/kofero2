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
import java.security.SecureRandom


@RestController
@RequestMapping("/auth")
class AuthController(
    @Autowired private val accountRepository: AccountRepository,

    @Autowired private val accountQueryService: AccountQueryService,

    @Autowired private val service: Account.AccountIdGenerationService
) {
    private fun isBlacklisted(uid: String) = false

    @PutMapping("/register")
    fun register(@RequestBody request: RegisterAuthRequest): ResponseEntity<Any> {
        fun getSalt() = ByteArray(16).apply { SecureRandom().nextBytes(this) }
        val split = request.prefixedUid.split(authDelimiter)
        if (split.size != 2 || split[0] != authPrefix || isBlacklisted(split[1])) {
            return ResponseEntity(HttpStatus.UNAUTHORIZED)
        }
        val salt = getSalt()
        val secret = split[1].getHash(getSalt())
        val hash = secret.getHash(salt)

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

        return ResponseEntity(
            RegisterAuthResponse(System.currentTimeMillis(), "${account.id}$authDelimiter$secret"),
            HttpStatus.OK
        )
    }
}
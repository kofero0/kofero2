package ro.kofe.web

import lombok.AllArgsConstructor
import lombok.Builder
import lombok.NoArgsConstructor
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.stereotype.Repository
import org.springframework.stereotype.Service
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.PathVariable
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController
import java.util.*
import javax.persistence.*


@Entity
@Table(name = "account")
@lombok.Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
class Account(
    @Id var id: Long = 0L,
    var deviceId: String = "",
    var salt: ByteArray = ByteArray(0),
    var hash: String = "",
    var privilege: Privilege = Privilege.USER,
    var expiration: Long = 0L,
    var status: Status = Status.REVOKED
) {

    enum class Status {
        VALID, REVOKED
    }

    enum class Privilege {
        USER, ADMIN
    }
}

@Repository
interface AccountRepository : JpaRepository<Account?, Long?> {
    fun findByDeviceId(deviceId: String): Optional<Account?>
}


@Entity
@Table(name = "account")
@lombok.Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
class BlacklistEntry(
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    var id:Long = 0L,
    var deviceId: String = ""
)

@Repository
interface BlacklistRepository: JpaRepository<BlacklistEntry?, Long?>

@Service
class AccountQueryService(
    @Autowired private val accountRepository: AccountRepository
) {
    fun getAccountById(accountId: Long) = if (accountRepository.findById(accountId).isEmpty) {
        null
    } else {
        accountRepository.findById(accountId).get()
    }

    fun getAccountByDeviceId(deviceId: String) = if (accountRepository.findByDeviceId(deviceId).isEmpty) {
        null
    } else {
        accountRepository.findByDeviceId(deviceId).get()
    }
}

@Service
class AccountIdGenerationService {
    var nextId = 0L
    fun newAccountId() = nextId++
}

@Service
class MockAccountGenerateService(
    @Autowired private val accountRepository: AccountRepository,

    @Autowired private val service: AccountIdGenerationService

) {
    fun generateAccounts() {
        val account1 = Account(
            id = service.newAccountId(),
            salt = "test".toByteArray(),
            hash = "tset",
            privilege = Account.Privilege.ADMIN,
            expiration = 345345,
            status = Account.Status.VALID
        )
        accountRepository.save(account1)
        val account2 = Account(
            id = service.newAccountId(),
            salt = "salt".toByteArray(),
            hash = "ppqpppqppq",
            privilege = Account.Privilege.USER,
            expiration = 111,
            status = Account.Status.REVOKED
        )
        accountRepository.save(account2)
    }
}

@RestController
@RequestMapping("/account")
class AccountQueryController(private val service: AccountQueryService) {
    @GetMapping("/{accountId}")
    fun getAccountById(@PathVariable(value = "accountId") accountId: Long): ResponseEntity<Account> {
        val opt = service.getAccountById(accountId)
        return if (opt == null) {
            ResponseEntity.notFound().build()
        } else {
            ResponseEntity<Account>(opt, HttpStatus.OK)
        }
    }
}


@RestController
@RequestMapping("/mockaccount")
class MockAccountController(private val dummyAccountGenerateService: MockAccountGenerateService) {
    @GetMapping("/generatedummyaccounts")
    fun generateDummyAccounts() {
        dummyAccountGenerateService.generateAccounts()
    }
}
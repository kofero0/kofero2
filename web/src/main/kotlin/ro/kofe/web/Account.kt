package ro.kofe.web

import lombok.AllArgsConstructor
import lombok.Builder
import lombok.NoArgsConstructor
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.stereotype.Service
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.PathVariable
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController
import java.math.BigDecimal
import javax.persistence.Entity
import javax.persistence.Id
import javax.persistence.Table


@Entity
@Table(name = "account")
@lombok.Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
data class Account(
    @Id private val id: Long? = null, private val name: String? = null, private val balance: BigDecimal? = null
)


interface AccountRepository : JpaRepository<Account?, Long?>


@Service
class AccountQueryService(
    @Autowired private val accountRepository: AccountRepository
) {

    fun getAccountById(accountId: Long) = if (accountRepository.findById(accountId).isEmpty) {
        null
    } else {
        accountRepository.findById(accountId).get()
    }

    val accounts: List<Account?>
        get() = accountRepository.findAll()
}


@Service
class AccountIdGenerationService {
    fun newAccountId(): Long {
        return System.nanoTime()
    }
}

@Service
class MockAccountGenerateService(

    @Autowired private val accountRepository: AccountRepository,

    @Autowired private val accountIdGenerationService: AccountIdGenerationService

) {
    fun generateAccounts() {
        val account1 = Account(
            id = accountIdGenerationService.newAccountId(), balance = BigDecimal(100), name = "Berkay account"
        )
        accountRepository.save(account1)
        val account2 = Account(
            id = accountIdGenerationService.newAccountId(), balance = BigDecimal(100), name = "Test account"
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

    @GetMapping("/list")
    fun getAccounts() = service.accounts
}


@RestController
@RequestMapping("/mockaccount")
class MockAccountController(private val dummyAccountGenerateService: MockAccountGenerateService) {
    @GetMapping("/generatedummyaccounts")
    fun generateDummyAccounts() {
        dummyAccountGenerateService.generateAccounts()
    }
}
package ro.kofe.web

import org.springframework.beans.factory.annotation.Autowired
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.stereotype.Service
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.PathVariable
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController


@Service
class MockAccountGenerateService(
    @Autowired private val accountRepository: AccountRepository,

    @Autowired private val service: Account.AccountIdGenerationService

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
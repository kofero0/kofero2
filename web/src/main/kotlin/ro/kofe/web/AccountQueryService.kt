package ro.kofe.web

import org.springframework.beans.factory.annotation.Autowired
import org.springframework.stereotype.Service


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
package ro.kofe.web

import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.stereotype.Repository
import java.util.*

@Repository
interface AccountRepository : JpaRepository<Account?, Long?> {
    fun findByDeviceId(deviceId: String): Optional<Account?>
}
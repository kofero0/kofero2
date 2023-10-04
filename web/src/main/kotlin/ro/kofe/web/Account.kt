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

    @Service
    class AccountIdGenerationService {
        var nextId = 0L
        fun newAccountId() = nextId++
    }
}
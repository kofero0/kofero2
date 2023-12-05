package ro.kofe.web

import lombok.AllArgsConstructor
import lombok.Builder
import lombok.NoArgsConstructor
import org.springframework.stereotype.Service
import javax.persistence.Entity
import javax.persistence.Id
import javax.persistence.Table


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
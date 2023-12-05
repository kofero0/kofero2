package ro.kofe.web

import lombok.AllArgsConstructor
import lombok.Builder
import lombok.NoArgsConstructor
import javax.persistence.*


@Entity
@Table(name = "account")
@lombok.Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
class BlacklistEntry(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    var id: Long = 0L,
    var deviceId: String = ""
)
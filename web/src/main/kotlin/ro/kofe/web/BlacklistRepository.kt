package ro.kofe.web

import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.stereotype.Repository


@Repository
interface BlacklistRepository: JpaRepository<BlacklistEntry?, Long?>
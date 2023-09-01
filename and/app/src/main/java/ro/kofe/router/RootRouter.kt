package ro.kofe.router

import androidx.fragment.app.FragmentManager
import androidx.navigation.NavController
import androidx.navigation.NavHost
import ro.kofe.model.Event
import ro.kofe.presenter.ipv.home.HomeKView
import ro.kofe.presenter.ipv.root.RootRouter
import ro.kofe.view.ViewBuilder

class RootRouterImpl(
    private val navController: NavController,
    private val homeBuilder: ViewBuilder<HomeKView>): RootRouter  {
    override fun routeTo(view: Event.ViewTag, uid: Int): Boolean {
    }
}
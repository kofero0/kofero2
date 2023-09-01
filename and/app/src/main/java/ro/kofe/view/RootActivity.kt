package ro.kofe.view

import android.os.Bundle
import android.view.View
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHost
import androidx.navigation.NavHostController
import dagger.hilt.android.AndroidEntryPoint
import ro.kofe.presenter.ipv.home.HomeKView
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootKView
import ro.kofe.provider.NavHostProvider
import ro.kofe.ui.theme.KoferoTheme
import javax.inject.Inject

@AndroidEntryPoint
class RootActivity : RootKView, ComponentActivity() {
    @Inject
    lateinit var interactor: RootInteractor

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        interactor.setView(this)

        setContent {
            KoferoTheme {
                Greeting("Android!")
            }
        }
    }

    override fun error(e: Exception) {
        TODO("Not yet implemented")
    }

    override fun onResume() {
        super.onResume()
        interactor.viewResumed()
    }

    override fun onPause() {
        super.onPause()
        interactor.viewPaused()
    }

    override fun onDestroy() {
        super.onDestroy()
        interactor.shutdown()
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    KoferoTheme {
        Greeting("Android")
    }
}
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
import dagger.hilt.android.AndroidEntryPoint
import ro.kofe.presenter.ipv.root.RootInteractor
import ro.kofe.presenter.ipv.root.RootKView
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
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Greeting("Android!")
                }
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
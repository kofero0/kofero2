package ro.kofe.view

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import dagger.hilt.android.AndroidEntryPoint
import ro.kofe.model.ViewTag
import ro.kofe.ui.HomeScreen
import ro.kofe.ui.KoferoAppBar
import ro.kofe.ui.theme.KoferoTheme

@AndroidEntryPoint
class RootActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            KoferoTheme {
                KoferoApp()
            }
        }
    }
}

@Composable
fun KoferoApp(
    viewModel: RootViewModel = viewModel(),
    navController: NavHostController = rememberNavController()
) {
    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Scaffold(
        topBar = {
            KoferoAppBar(
                canNavigateBack = false,
                navigateUp = { /* TODO: implement back navigation */ }
            )
        }
    ) { innerPadding ->
        NavHost(
            navController = navController,
            startDestination = ViewTag.HOME_VIEW.name,
            modifier = Modifier.padding(innerPadding)
        ) {
            composable(route = ViewTag.HOME_VIEW.name) {
                HomeScreen(
                    onNavigate = { viewTag -> navController.navigate(viewTag.name) }
                )
            }
            composable(route = ViewTag.GAME_VIEW.name) {

            }
            composable(route = ViewTag.CHAR_VIEW.name) {

            }
            composable(route = ViewTag.SETTINGS_VIEW.name) {

            }
        }
    }

}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    KoferoTheme {
        KoferoApp()
    }
}
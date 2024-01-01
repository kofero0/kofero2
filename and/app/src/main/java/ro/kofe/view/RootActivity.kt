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
import ro.kofe.ui.CharScreen
import ro.kofe.ui.GameScreen
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
    root: RootViewModel = viewModel(),
    home: HomeViewModel = viewModel(),
    game: GameViewModel = viewModel(),
    char: CharViewModel = viewModel(),
    appBar: AppBarViewModel = viewModel(),
    navController: NavHostController = rememberNavController()
) {
    DisposableEffect(key1 = root) {
        root.onStart()
        onDispose { root.onStop() }
    }

    Scaffold(topBar = {
        KoferoAppBar(appBar)
    }) { innerPadding ->
        NavHost(
            navController = navController,
            startDestination = ViewTag.HOME_VIEW.name,
            modifier = Modifier.padding(innerPadding)
        ) {
            composable(route = ViewTag.HOME_VIEW.name) {
                HomeScreen(viewModel = home, onNavigate = { viewTag, uid ->
                    navController.navigate("${viewTag.name}/$uid")
                    appBar.fromHome(uid) {
                        navController.popBackStack()
                        appBar.toHome(uid)
                    }
                })
            }
            composable(route = "${ViewTag.GAME_VIEW.name}/{uid}") {
                GameScreen(viewModel = game, onNavigate = { viewTag, uid ->
                    navController.navigate("${viewTag.name}/$uid")
                    appBar.toChar(uid) {
                        navController.popBackStack()
                    }
                }, it.arguments?.getString("uid"))
            }
            composable(route = "${ViewTag.CHAR_VIEW.name}/{uid}") {
                CharScreen(viewModel = char, uid = it.arguments?.getString("uid"))
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
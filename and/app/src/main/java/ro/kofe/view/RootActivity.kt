package ro.kofe.view

import android.os.Bundle
import android.util.DisplayMetrics
import androidx.activity.ComponentActivity
import androidx.activity.compose.BackHandler
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.viewinterop.AndroidView
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import com.google.android.gms.ads.AdRequest
import com.google.android.gms.ads.AdSize
import com.google.android.gms.ads.AdView
import com.google.android.gms.ads.MobileAds
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
        MobileAds.initialize(this)
    }
}




@Composable
fun AdmobBanner(modifier: Modifier = Modifier) {
    AndroidView(
        modifier = modifier.fillMaxWidth(),
        factory = { context ->
            AdView(context).apply {
                setAdSize(AdSize.BANNER)
                adUnitId = "ca-app-pub-3940256099942544~3347511713"
                loadAd(AdRequest.Builder().build())
            }
        }
    )
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
        appBar.setBackStackClosure { navController.popBackStack() }
        onDispose { root.onStop() }
    }

    Scaffold(topBar = {
        KoferoAppBar(appBar)
    }, bottomBar = {
        AdmobBanner()
    }) { innerPadding ->
        NavHost(
            navController = navController,
            startDestination = ViewTag.HOME_VIEW.name,
            modifier = Modifier.padding(innerPadding)
        ) {
            composable(route = ViewTag.HOME_VIEW.name) {
                HomeScreen(viewModel = home, onNavigate = { viewTag,gameUid, charUid ->
                    var route = "${viewTag.name}/$gameUid"
                    charUid?.let { route += "/$charUid" }
                    navController.navigate(route)
                    if(charUid == null){
                        appBar.fromHome(gameUid)
                    } else {
                        appBar.fromHome(charUid)
                    }
                })
            }
            composable(route = "${ViewTag.GAME_VIEW.name}/{uid}") {
                GameScreen(viewModel = game,
                    uid = it.arguments?.getString("uid"),
                    onNavigate = { viewTag, charUid, gameUid ->
                        navController.navigate("${viewTag.name}/$gameUid/$charUid")
                        appBar.toChar(charUid, gameUid)
                    },
                    onBackPressed = { appBar.navClicked.value.invoke() })
            }
            composable(route = "${ViewTag.CHAR_VIEW.name}/{gameUid}/{charUid}") {
                CharScreen(viewModel = char,
                    gameUid = it.arguments?.getString("gameUid"),
                    charUid = it.arguments?.getString("charUid"),
                    onBackPressed = { appBar.navClicked.value.invoke() })
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
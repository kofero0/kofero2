package ro.kofe.ui

import android.util.Log
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import ro.kofe.model.ViewTag
import ro.kofe.view.GameViewModel

@Composable
fun GameScreen(
    viewModel: GameViewModel,
    onNavigate: (ViewTag, Int) -> Unit,
    uid: String?,
    modifier: Modifier = Modifier
) {
    Log.v("rwr", "GAME UID: $uid")
    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }
}
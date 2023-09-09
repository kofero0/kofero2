package ro.kofe.ui

import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import ro.kofe.model.ViewTag
import ro.kofe.view.GameViewModel

@Composable
fun GameScreen(
    viewModel: GameViewModel,
    onNavigate: (ViewTag) -> Unit,
    modifier: Modifier = Modifier
){
    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

}
package ro.kofe.ui

import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import ro.kofe.view.CharViewModel

@Composable
fun CharScreen(
    viewModel: CharViewModel,
    modifier: Modifier = Modifier
){
    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

}
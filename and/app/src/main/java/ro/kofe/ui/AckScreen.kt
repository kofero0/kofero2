package ro.kofe.ui

import androidx.activity.compose.BackHandler
import androidx.compose.foundation.layout.Column
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import ro.kofe.model.ViewTag
import ro.kofe.view.AckViewModel
import ro.kofe.view.GameViewModel

@Composable
fun AckScreen(
    viewModel: AckViewModel,
    onBackPressed: () -> Unit,
    modifier: Modifier = Modifier
) {

    BackHandler {
        onBackPressed()
    }
    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }
    Column {

    }
}
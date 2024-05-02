package ro.kofe.ui

import androidx.activity.compose.BackHandler
import androidx.compose.foundation.layout.Column
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.ui.Modifier
import ro.kofe.view.AboutViewModel

@Composable
fun AboutScreen(
    viewModel: AboutViewModel,
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
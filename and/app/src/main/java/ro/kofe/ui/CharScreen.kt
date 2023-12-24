package ro.kofe.ui

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import ro.kofe.view.CharViewModel

@Composable
fun CharScreen(
    viewModel: CharViewModel,
    modifier: Modifier = Modifier,
    uid: String?
) {

    val char by viewModel.char.collectAsState()
    val moves by viewModel.moves.collectAsState()
    val images by viewModel.images.collectAsState()

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {
        Text("")
        Image()
        
    }


}
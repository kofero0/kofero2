package ro.kofe.ui

import android.util.Log
import androidx.activity.compose.BackHandler
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import ro.kofe.model.ViewTag
import ro.kofe.view.GameViewModel

@Composable
fun GameScreen(
    viewModel: GameViewModel,
    onNavigate: (ViewTag, Int, Int) -> Unit,
    onBackPressed: () -> Unit,
    uid: String?,
    modifier: Modifier = Modifier
) {
    uid?.let { viewModel.setGameUid(it.toInt()) }
    val game by viewModel.game.collectAsState()
    val chars by viewModel.chars.collectAsState()
    val images by viewModel.images.collectAsState()

    BackHandler {
        onBackPressed()
    }

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {
        game?.let { uGame ->
            LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 200.dp)) {
                items(chars.size) {
                    RowItem(chars[it].name,images[chars[it].iconUrl]) {
                        viewModel.charPressed(chars[it])
                        onNavigate(ViewTag.CHAR_VIEW, chars[it].uid, uGame.uid)
                    }
                }
            }
        }
    }
}
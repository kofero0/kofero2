package ro.kofe.ui

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
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.ViewTag
import ro.kofe.view.HomeViewModel


@Composable
fun HomeScreen(
    viewModel: HomeViewModel,
    onNavigate: (ViewTag, Int) -> Unit,
    modifier: Modifier = Modifier
) {
    val favs by viewModel.favs.collectAsState()
    val games by viewModel.games.collectAsState()
    val images by viewModel.images.collectAsState()

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {

        Text("Favorites")

        LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 128.dp)) {
            items(favs.size) {
                FavItem(favs[it], images) {
                    viewModel.favPressed(favs[it])
                    when (val fav = favs[it]) {
                        is Character -> onNavigate(ViewTag.CHAR_VIEW, fav.uid)
                        is Game -> onNavigate(ViewTag.GAME_VIEW, fav.uid)
                    }
                }
            }
        }

        Text("Games")

        LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 128.dp)) {
            items(games.size) {
                RowItem(games[it].name, images[games[it].iconUrl]) {
                    viewModel.gamePressed(games[it])
                    onNavigate(ViewTag.GAME_VIEW, games[it].uid)
                }
            }
        }
    }
}
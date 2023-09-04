package ro.kofe.ui

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.lifecycle.viewmodel.compose.viewModel
import ro.kofe.model.ViewTag
import ro.kofe.view.HomeViewModel


@Composable
fun HomeScreen(
    viewModel: HomeViewModel = viewModel(),
    onNavigate: (ViewTag) -> Unit,
    modifier: Modifier = Modifier
) {
    val favs by viewModel.favs.collectAsState()
    val games by viewModel.games.collectAsState()
    val images by viewModel.images.collectAsState()

    DisposableEffect(key1 = viewModel) {
        //viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {
        LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 128.dp)){
            items(favs.size){
                favs.forEach { obj ->
                    FavItem(obj, images){
                        viewModel.favPressed(obj)
                    }
                }
            }
        }

        LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 128.dp)){
            items(games.size){
                games.forEach {game ->
                    GameItem(game, images){
                        viewModel.gamePressed(game)
                    }
                }
            }
        }
    }
}
package ro.kofe.ui

import android.content.res.Resources
import android.util.Log
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.res.vectorResource
import androidx.compose.ui.unit.dp
import ro.kofe.R
import ro.kofe.model.Character
import ro.kofe.model.Game
import ro.kofe.model.ViewTag
import ro.kofe.view.HomeViewModel


@Composable
fun HomeScreen(
    viewModel: HomeViewModel,
    onNavigate: (ViewTag, Int, Int?) -> Unit,
    modifier: Modifier = Modifier
) {
    val favs by viewModel.favs.collectAsState()
    val games by viewModel.games.collectAsState()
    val images by viewModel.images.collectAsState()

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    LazyVerticalGrid(columns = GridCells.Adaptive(minSize = 200.dp)){
        item{
            RowItem(title = "Sort", vector = ImageVector.vectorResource(R.drawable.sort)) {

            }
        }
        items(favs.size) {
            val fav = favs[it]
            fav.character?.also { char ->
                RowItem(title = char.name, image = images[char.iconUrl], emptyImage = R.drawable.emptychar) {
                    viewModel.favPressed(fav)
                    onNavigate(ViewTag.CHAR_VIEW, fav.game.uid, char.uid)
                }
            } ?: run {
                RowItem(title = fav.game.name, image = images[fav.game.iconUrl], emptyImage = R.drawable.emptygame) {
                    viewModel.favPressed(fav)
                    onNavigate(ViewTag.GAME_VIEW, fav.game.uid, null)
                }
            }
        }
        items(games.size) {
            if(favs.find {fav -> games[it].uid == fav.game.uid && fav.character == null } == null) {
                RowItem(games[it].name, images[games[it].iconUrl]) {
                    viewModel.gamePressed(games[it])
                    onNavigate(ViewTag.GAME_VIEW, games[it].uid, null)
                }
            }
        }
        item{
            RowItem(title = "Acknowledgements", vector = ImageVector.vectorResource(R.drawable.attribution)){

            }
        }
        item{
            RowItem(title = "About", vector = ImageVector.vectorResource(R.drawable.info)) {

            }
        }
    }
}
package ro.kofe.ui

import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.material.icons.filled.Favorite
import androidx.compose.material.icons.outlined.FavoriteBorder
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBar
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import ro.kofe.frames.R
import ro.kofe.view.AppBarViewModel


@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun KoferoAppBar(
    viewModel: AppBarViewModel, modifier: Modifier = Modifier
) {
    val title by viewModel.title.collectAsState()
    val canNavigateBack by viewModel.canNavigateBack.collectAsState()
    val navClicked by viewModel.navClicked.collectAsState()
    val favClicked by viewModel.favoriteClicked.collectAsState()
    val canFavorite by viewModel.canFavorite.collectAsState()
    val isFavorited by viewModel.isFavorited.collectAsState()


    TopAppBar(title = { Text(title) }, colors = TopAppBarDefaults.mediumTopAppBarColors(
        containerColor = MaterialTheme.colorScheme.primaryContainer
    ), modifier = modifier, navigationIcon = {
        if (canNavigateBack) {
            IconButton(onClick = navClicked) {
                Icon(
                    imageVector = Icons.Filled.ArrowBack,
                    contentDescription = stringResource(R.string.back_button)
                )
            }
        }
    }, actions = {
        if (canFavorite) {
            IconButton(onClick = { favClicked() }) {
                val icon = if (isFavorited) {
                    Icons.Filled.Favorite
                } else {
                    Icons.Outlined.FavoriteBorder
                }
                Icon(
                    imageVector = icon,
                    contentDescription = stringResource(R.string.favorite)
                )
            }
        }
    })
}
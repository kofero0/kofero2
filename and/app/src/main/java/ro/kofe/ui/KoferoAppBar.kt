package ro.kofe.ui

import androidx.compose.foundation.layout.RowScope
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.material.icons.filled.Refresh
import androidx.compose.material.icons.filled.Star
import androidx.compose.material.icons.outlined.Star
import androidx.compose.material.icons.sharp.Star
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import ro.kofe.R
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
                    Icons.Filled.Star
                } else {
                    Icons.Outlined.Star
                }
                Icon(
                    imageVector = icon, contentDescription = stringResource(R.string.favorite)
                )
            }
        }
    })
}
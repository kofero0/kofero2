package ro.kofe.ui

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import ro.kofe.model.Game
import ro.kofe.toBase64ImageToImageBitmap


@Composable
fun GameItem(game: Game, images:Map<String,String>, onClick:() -> Unit){
    Column {
        Image(bitmap = images[game.iconUrl].toBase64ImageToImageBitmap(), contentDescription = game.name)
        Text(text = game.name)
    }

}
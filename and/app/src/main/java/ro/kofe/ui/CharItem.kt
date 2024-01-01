package ro.kofe.ui

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import ro.kofe.model.Character
import ro.kofe.toBase64ImageToImageBitmap

@Composable
fun CharItem(char: Character, images: Map<String, String>, onClick: () -> Unit) {
    Button(onClick = onClick) {
        Column {
            Image(
                bitmap = images[char.iconUrl].toBase64ImageToImageBitmap(),
                contentDescription = char.name
            )
            Text(text = char.name)
        }
    }
}
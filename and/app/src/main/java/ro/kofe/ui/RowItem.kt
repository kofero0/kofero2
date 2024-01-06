package ro.kofe.ui

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.size
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import ro.kofe.toBase64ImageToImageBitmap


@Composable
fun RowItem(title: String, image: String?, onClick: () -> Unit) {
    Button(onClick = onClick) {
        Column {
            image?.let{
//                Image(
//                    bitmap = it.toBase64ImageToImageBitmap(),
//                    contentDescription = title,
//                    //modifier = Modifier.fillMaxSize(),
//                    modifier = Modifier.size(100.dp),
//                    colorFilter = null
//                )
            }
            Text(text = title)
        }
    }
}
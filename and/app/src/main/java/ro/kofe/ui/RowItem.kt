package ro.kofe.ui

import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.unit.dp
import ro.kofe.toBase64ImageToImageBitmap


@Composable
fun RowItem(title: String, image: String?, onClick: () -> Unit, vector: ImageVector?) {
    OutlinedButton(
        onClick = onClick,
        border = BorderStroke(1.dp, Color.Black),
        shape = RoundedCornerShape(25),
        colors = ButtonDefaults.outlinedButtonColors(contentColor = Color.Black)
    ) {
        Column {
            image?.let {
                Image(
                    bitmap = it.toBase64ImageToImageBitmap(),
                    contentDescription = title,
                    modifier = Modifier.size(100.dp),
                    colorFilter = null
                )
            }
            vector?.let {
                Image(
                    imageVector = vector,
                    contentDescription = title,
                    modifier = Modifier.size(100.dp),
                    colorFilter = null
                )
            }
            Text(text = title)
        }
    }
}
package ro.kofe.ui

import android.util.Log
import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import ro.kofe.toBase64ImageToImageBitmap


@Composable
fun RowItem(title: String, image: String? = null, vector: ImageVector? = null, emptyImage: Int? = null, onClick: () -> Unit) {
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
                    modifier = Modifier
                        .size(100.dp)
                        .align(Alignment.CenterHorizontally),
                    colorFilter = null
                )
            }
            if(image == null && emptyImage != null){
                Image(
                    painterResource(id = emptyImage),
                    contentDescription = title,
                    modifier = Modifier
                        .size(100.dp)
                        .align(Alignment.CenterHorizontally)
                )
            }
            vector?.let {
                Image(
                    imageVector = vector,
                    contentDescription = title,
                    modifier = Modifier
                        .size(100.dp)
                        .align(Alignment.CenterHorizontally),
                    colorFilter = null
                )
            }
            Text(text = title, modifier = Modifier.align(Alignment.CenterHorizontally))
        }
    }
}
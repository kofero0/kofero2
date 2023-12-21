package ro.kofe

import android.graphics.BitmapFactory
import android.util.Base64
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.asImageBitmap


fun String?.toBase64ImageToImageBitmap() = if (this == null) {
    ImageBitmap(1,1)
} else {
    val decodedString = Base64.decode(this, Base64.DEFAULT)
    BitmapFactory.decodeByteArray(decodedString, 0, decodedString.size).asImageBitmap()
}
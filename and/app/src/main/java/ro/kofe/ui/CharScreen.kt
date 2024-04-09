package ro.kofe.ui

import androidx.activity.compose.BackHandler
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.wrapContentHeight
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.LazyListScope
import androidx.compose.material3.Icon
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.toMutableStateMap
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import ro.kofe.frames.R
import ro.kofe.view.CharViewModel

data class MoveData(val moveName: String, val attributes: Map<String, String>)

@Composable
fun MoveItem(text: String) {
    Text(
        text = text,
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 8.dp, horizontal = 16.dp)
            .padding(start = 50.dp)
    )
}

@Composable
fun MoveHeader(text: String, isExpanded: Boolean, onClick: () -> Unit) {
    Row(modifier = Modifier
        .clickable { onClick() }
        .background(Color.White)
        .padding(vertical = 20.dp, horizontal = 20.dp)) {
        val chevron = if (isExpanded) {
            R.drawable.chevron_up
        } else {
            R.drawable.chevron_down
        }
        Icon(
            painter = painterResource(id = chevron),
            contentDescription = "Localized description",
            modifier = Modifier
                .weight(0.1f)
        )
        Text(
            text = text,
            fontSize = 20.sp,
            modifier = Modifier
                .weight(1.0f)
                .wrapContentHeight(Alignment.CenterVertically)
        )
    }
}

fun LazyListScope.MoveSection(
    moveData: MoveData,
    isExpanded: Boolean,
    onClick: () -> Unit
) {

    item {
        MoveHeader(
            text = moveData.moveName,
            isExpanded = isExpanded,
            onClick = onClick
        )
    }

    if (isExpanded) {
        items(moveData.attributes.size) {
            val entry = moveData.attributes.entries.toList()[it]
            MoveItem(text = "${entry.key}: ${entry.value}")
        }
    }
}

@Composable
fun ExpandableList(moves: List<MoveData>) {
    val isExpandedMap =
        List(moves.size) { index: Int -> index to false }
            .toMutableStateMap()

    LazyColumn(
        content = {
            moves.onEachIndexed { index, moveData ->
                MoveSection(
                    moveData = moveData,
                    isExpanded = isExpandedMap[index] ?: false,
                    onClick = {
                        isExpandedMap[index] = !(isExpandedMap[index] ?: true)
                    }
                )
            }
        }
    )
}


@Composable
fun CharScreen(
    viewModel: CharViewModel,
    onBackPressed: () -> Unit,
    modifier: Modifier = Modifier,
    gameUid: String?,
    charUid: String?
) {
    charUid?.let { cUid ->
        gameUid?.let { gUid ->
            viewModel.setCharUid(cUid.toInt(), gUid.toInt())
        }
    }
    val char by viewModel.char.collectAsState()
    val moves by viewModel.moves.collectAsState()
    val images by viewModel.images.collectAsState()

    BackHandler {
        onBackPressed()
    }

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {
        char?.let {
            for (attribute in it.attributes) {
                Text("${attribute.key}: ${attribute.value}")
            }
        }
        ExpandableList(moves = ArrayList<MoveData>().apply {
            for (move in moves) {
                add(MoveData(move.name, move.attributes))
            }
        })
        //Image()
    }
}
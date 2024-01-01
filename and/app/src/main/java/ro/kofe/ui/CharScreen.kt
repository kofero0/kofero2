package ro.kofe.ui

import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.LazyListScope
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.runtime.toMutableStateMap
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import ro.kofe.view.CharViewModel

data class MoveData(val moveName: String, val attributes: List<String>)

@Composable
fun MoveItem(text: String) {
    Text(
        text = text,
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 8.dp, horizontal = 16.dp)
    )
}

@Composable
fun MoveHeader(text: String, isExpanded: Boolean, onClick: () -> Unit) {
    Row(modifier = Modifier
        .clickable { onClick() }
        .background(Color.LightGray)
        .padding(vertical = 8.dp, horizontal = 16.dp)) {
        Text(
            text = text,
            modifier = Modifier.weight(1.0f)
        )
        if (isExpanded) {
            //ExpandedChevronIcon()
        } else {
            //CollapsedChevronIcon()
        }
    }
}

fun LazyListScope.Section(
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
        items(moveData.attributes) {
            MoveItem(text = it)
        }
    }
}

@Composable
fun ExpandableList(moves: List<MoveData>) {
    val isExpandedMap = rememberSaveable {
        List(moves.size) { index: Int -> index to true }
            .toMutableStateMap()
    }

    LazyColumn(
        content = {
            moves.onEachIndexed { index, moveData ->
                Section(
                    moveData = moveData,
                    isExpanded = isExpandedMap[index] ?: true,
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
    modifier: Modifier = Modifier,
    uid: String?
) {
    val char by viewModel.char.collectAsState()
    val moves by viewModel.moves.collectAsState()
    val images by viewModel.images.collectAsState()

    DisposableEffect(key1 = viewModel) {
        viewModel.onStart()
        onDispose { viewModel.onStop() }
    }

    Column {
        Text("T E S T")
        ExpandableList(moves = ArrayList<MoveData>().apply {
            add(
                MoveData(
                    "test test",
                    ArrayList<String>().apply { add("tester") })
            )
        })
        //Image()
    }
}
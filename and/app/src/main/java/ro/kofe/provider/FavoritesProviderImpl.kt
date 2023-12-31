package ro.kofe.provider

import android.content.Context
import android.util.Log
import arrow.core.raise.either
import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import ro.kofe.model.Favorite
import ro.kofe.model.IdsNotFound
import ro.kofe.model.InvalidObject
import ro.kofe.model.ProviderError
import ro.kofe.presenter.provider.FavoritesProvider
import java.io.File

class FavoritesProviderImpl(private val context: Context, private val gson: Gson) : FavoritesProvider {
    private val file: File by lazy {
        File(
            context.filesDir,
            "favs.json"
        ).apply {
            if (!exists()){
                createNewFile()
                writeBytes("[]".toByteArray())
            }
        }
    }

    override suspend fun delete(id: Int) = either {
        val favs = gson.fromJson<ArrayList<Favorite>>(file.readText(),object : TypeToken<ArrayList<Favorite>>() {}.type)
        if(favs.any{it.uid == id}){
            file.writeText(gson.toJson(favs.apply { favs.removeIf { it.uid == id } }))
        }
        else{
            raise(IdsNotFound(ArrayList<Int>().apply { add(id) }))
        }
    }

    override suspend fun get() = either<ProviderError,List<Favorite>> {
        val favs = gson.fromJson<ArrayList<Favorite>>(file.readText(), object: TypeToken<ArrayList<Favorite>>() {}.type)
        favs
    }

    override suspend fun save(fav: Favorite) = either<ProviderError, Unit> {
        val favs = gson.fromJson<ArrayList<Favorite>>(file.readText(),object : TypeToken<ArrayList<Favorite>>() {}.type)
        if(favs.contains(fav)){
            raise(InvalidObject(fav.uid))
        }
        else{
            file.writeText(gson.toJson(favs.apply { add(fav) }))
        }
    }
}
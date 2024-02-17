package ro.kofe.provider

import android.content.Context
import android.util.Log
import arrow.core.Either
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

    override suspend fun get() = either<ProviderError,List<Favorite>> {
        gson.fromJson<ArrayList<Favorite>>(file.readText(), object: TypeToken<ArrayList<Favorite>>() {}.type)
    }

    override suspend fun save(fav: Favorite) = either<ProviderError, Unit> {
        val favs = gson.fromJson<ArrayList<Favorite>>(file.readText(),object : TypeToken<ArrayList<Favorite>>() {}.type)
        if(favs.contains(fav)){
            raise(IdsNotFound(ArrayList()))
        }
        else{
            file.writeText(gson.toJson(favs.apply { add(fav) }))
        }
    }

    override suspend fun delete(fav: Favorite) = either {
        val favs = gson.fromJson<ArrayList<Favorite>>(file.readText(),object : TypeToken<ArrayList<Favorite>>() {}.type)
        if(favs.contains(fav)){
            file.writeText(gson.toJson(favs.apply { remove(fav) }))
        }
        else{
            raise(IdsNotFound(ArrayList()))
        }
    }
}
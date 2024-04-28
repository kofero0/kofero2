package ro.kofe.map

import ro.kofe.presenter.map.Mapper

class QueryMapper: Mapper<List<String>, String> {
    override fun mapRight(data: List<String>): String {
        var ret = ""
        for(str in data){
            ret+=str
        }
        return ret
    }

    override fun mapLeft(data: String) = data.split(" ")
}
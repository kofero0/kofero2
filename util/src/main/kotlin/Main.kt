package org.example

import com.google.gson.Gson
import com.google.gson.JsonElement
import com.google.gson.JsonObject
import com.google.gson.JsonPrimitive
import com.google.gson.reflect.TypeToken
import java.io.File
import kotlin.collections.ArrayList

fun main() {
    println("Hello World!")
    //addTime()
}


fun formatMoveAttributesToStrings(){
    val gson = Gson()
    val oldType = object : TypeToken<ArrayList<JsonObject>>() {}.type

    val oldFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/old.json")
    val newFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/new.json")
    val oldList = gson.fromJson<ArrayList<JsonObject>>(oldFile.bufferedReader().readText(), oldType)
    val newList = ArrayList<JsonObject>()


    for(element in oldList){
        val newElement = JsonObject()
        newElement.add("uid", element.get("uid"))
        newElement.add("name", element.get("name"))
        val newAttributes = JsonObject()
        val attributes = element.get("attributes")
        println(element.get("uid").asString)
        //println(attributes.asJsonObject.keySet().size)
        for(itemKey in attributes.asJsonObject.keySet()){
            newAttributes.addProperty(itemKey,attributes.asJsonObject[itemKey].asString)
        }
        newElement.add("attributes",newAttributes)
        newList.add(newElement)
    }
    newFile.writeText("")
    newFile.writeText(gson.toJson(newList))
}


fun formatMove(){

    val gson = Gson()
    val oldType = object : TypeToken<ArrayList<JsonObject>>() {}.type

    val oldFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/old.json")
    val newFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/new.json")
    val oldList = gson.fromJson<ArrayList<JsonObject>>(oldFile.bufferedReader().readText(), oldType)
    val newList = ArrayList<JsonObject>()
    for(element in oldList){
        val uid = element.get("uid")
        val name = element.get("name")
        element.remove("uid")
        element.remove("name")
        newList.add(JsonObject().apply {
            add("uid", uid)
            add("name",name)
            add("attributes",element)
        })
    }
    newFile.writeText("")
    val json = gson.toJson(newList)
    newFile.writeText(json.substring(1,json.length-1))
}

fun addTimeGames(){
    val gson = Gson()
    val oldType = object : TypeToken<ArrayList<JsonObject>>() {}.type

    val oldFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/old.json")
    val newFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/new.json")
    val oldList = gson.fromJson<ArrayList<JsonObject>>(oldFile.bufferedReader().readText(), oldType)
    val newList = ArrayList<JsonObject>()
    for(element in oldList){
        val uid = element.get("uid")
        val name = element.get("name")
        newList.add(JsonObject().apply {
            add("uid", uid)
            add("name",name)
            add("attributes",element.get("attributes"))
            add("date",JsonPrimitive(0L))
            add("moveIds",element.get("moveIds"))
            add("iconUrl", element.get("iconUrl"))
        })
    }
    newFile.writeText("")
    newFile.writeText(gson.toJson(newList))
}

fun addTimeChars(){
    val gson = Gson()
    val oldType = object : TypeToken<ArrayList<JsonObject>>() {}.type

    val oldFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/old.json")
    val newFile = File("/Users/mdrew/workspace/koferoutil/src/main/kotlin/new.json")
    val oldList = gson.fromJson<ArrayList<JsonObject>>(oldFile.bufferedReader().readText(), oldType)
    val newList = ArrayList<JsonObject>()
    for(element in oldList){
        val uid = element.get("uid")
        val name = element.get("name")
        newList.add(JsonObject().apply {
            add("uid", uid)
            add("name",name)
            add("attributes",element.get("attributes"))
            add("date",JsonPrimitive(0L))
            add("moveIds",element.get("moveIds"))
            add("iconUrl", element.get("iconUrl"))
        })
    }
    newFile.writeText("")
    newFile.writeText(gson.toJson(newList))
}
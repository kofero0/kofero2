//
//  Provider.swift
//  provider
//
//  Created by Mitchell Drew on 1/4/21.
//

import Foundation
import presenter

open class ProviderImpl<O:ModelObj>: Provider {
    private let arrowExtensions = ArrowExtensions()
    private let restManager: RestManager
    private let fileManager: IFileManager
    private let userDefaults: IUserDefaults
    private let encoder:DataEncoder<[Int32]>
    private let mapper:DataMapper<[O]>
    private let jsonFilename: String
    private let url:URL
    
    private var isDiskPulled = false
    private var requests = [[KotlinInt]:RestTask]()
    private var elements = [O]()
    
    public init(core:ProviderCore, url:URL, mapper:DataMapper<[O]>, jsonFilename:String, loggingProvider:LoggingProvider){
        self.fileManager = core.fileManager
        self.restManager = core.restManager
        self.userDefaults = core.userDefaults
        self.encoder = core.requestEncoder
        self.url = url
        self.mapper = mapper
        self.jsonFilename = jsonFilename
    }
    
    public func get(ids: [KotlinInt]) async throws -> Arrow_coreIor<ModelProviderError, NSArray> {
        if(!isDiskPulled){
            return try await pullFromDisk(ids: ids)
        }
        else{
            if(isSatisfiable(request: ids)){
                return arrowExtensions.buildListIorRight(right: retrieve(ids: ids))
            }
            else{
                return try await send(ids: ids)
            }
        }
    }
    
    private func send(ids: [KotlinInt]) async throws -> Arrow_coreIor<ModelProviderError, NSArray> {
        let group = DispatchGroup()
        var providerError:ModelProviderError? = nil
        var result: [O]? = nil
        group.enter()
        let task = restManager.dataTask(with: try createRequest(ids: ids)){[self] data, response, error in
            if(isResponseGood(data:data, response:response, error:error)){
                do{ try add(new: try mapper.map(data: data!))
                    result = elements
                }
                catch {
                    providerError = ModelIncorrectCount(ids: [])
                }
            }
            else{
                providerError = ModelIncorrectCount(ids: [])
            }
            group.leave()
        }
        requests.updateValue(task, forKey: ids)
        task.resume()
        group.wait()
        if let uPError = providerError {
            if let uResult = result {
                return arrowExtensions.buildListIorBoth(left: uPError, right: uResult)
            }
            return arrowExtensions.buildListIorLeft(left: uPError)
        }
        if let uResult = result {
            return arrowExtensions.buildListIorRight(right: uResult)
        }
        return arrowExtensions.buildListIorLeft(left: ModelOther())
    }
    
    
    private func isResponseGood(data:Data?, response:URLResponse?, error:Error?) -> Bool {
        return data != nil && (response as! HTTPURLResponse).statusCode == 200 && error == nil
    }
    
    private func isSatisfiable(request: [KotlinInt]) -> Bool {
        for id in request {
            if(!elements.contains(where: {element in return element.uid == id.int32Value})){ return false }
        }
        return true
    }
    
    private func add(new:[O]) throws {
        for element in new {
            elements.removeAll(where: {existingElement in return element.uid == existingElement.uid})
            elements.append(element)
        }
        try mapper.map(data: elements).write(to: makeUrl(string: jsonFilename), options: .atomic)
        for request in requests.keys {
            if(isSatisfiable(request: request)){
                requests.removeValue(forKey: request)?.cancel()
            }
        }
    }
    
    private func makeUrl(string:String) -> URL {
        return fileManager.urls(for: .documentDirectory, in: .userDomainMask)[0].appendingPathComponent("\(string)")
    }
    
    private func createRequest(ids: [KotlinInt]) throws -> URLRequest {
        var ret = URLRequest(url: url)
        var ids32 = [Int32]()
        for id in ids{ ids32.append(id.int32Value) }
        try ret.httpBody = encoder.encode(ids32)
        return ret
    }
    
    
    private func retrieve(ids: [KotlinInt]) -> [O] {
        if(ids.isEmpty){ return elements }
        var ret = [O]()
        for id in ids {
            ret.append(elements.first(where: {element in return element.uid == id.int32Value})!)
        }
        return ret
    }
    
    private func pullFromDisk(ids: [KotlinInt]) async throws -> Arrow_coreIor<ModelProviderError, NSArray> {
        isDiskPulled = true
        let url = makeUrl(string: jsonFilename)
        do {
            elements = try mapper.map(data: Data(contentsOf: url))
            return arrowExtensions.buildListIorRight(right: elements)
        }
        catch {
            return try pullFromBundledJson(ids:ids)
        }
        if(isSatisfiable(request: ids)){
            return arrowExtensions.buildListIorRight(right: retrieve(ids: ids))
        }
        else{
            return try await send(ids: ids)
        }
    }
    
    private func pullFromBundledJson(ids:[KotlinInt]) throws -> Arrow_coreIor<ModelProviderError, NSArray> {
        if let path = Bundle.main.path(forResource: jsonFilename, ofType: "json") {
                elements = try mapper.map(data: Data(contentsOf: URL(fileURLWithPath: path), options: .alwaysMapped))
            return arrowExtensions.buildListIorRight(right: elements)
        } else {
            return arrowExtensions.buildListIorLeft(left: ModelFileReadError(filePath: jsonFilename))
        }
    }
}

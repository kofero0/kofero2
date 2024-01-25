//
//  DiskAccessor.swift
//  kofero
//
//  Created by Mitchell Drew on 24/1/24.
//

import Foundation
import presenter

class DiskAccessorImpl: DiskAccessor {
    let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first
    
    func read(fileName: String) -> String {
        let fileUrl = dir!.appendingPathComponent("kofero" + fileName + ".txt")
        do{
            return try String(contentsOf: fileUrl, encoding: .utf8)
        }
        catch{
            fatalError("how did we get here?")
        }
    }
    
    func write(fileName: String, json: String) {
        let fileUrl = dir!.appendingPathComponent("kofero" + fileName + ".txt")
        do{
            try json.write(to: fileUrl, atomically: true, encoding: .utf8)
        }
        catch{
            fatalError("how did we get here?")
        }
    }
}

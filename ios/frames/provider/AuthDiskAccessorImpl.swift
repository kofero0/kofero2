//
//  AuthDiskAccessorImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 1/2/24.
//

import Foundation
import presenter

class AuthDiskAccessorImpl: AuthDiskAccessor {
    let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first
    let syncObject = NSObject()
    
    func read() -> String {
        synchronized(syncObject){
            let fileUrl = dir!.appendingPathComponent("koferoAuth.txt")
            do{
                return try String(contentsOf: fileUrl, encoding: .utf8)
            }
            catch{
                return String("")
            }
        }
    }
    
    func save(token:String) {
        synchronized(syncObject){
            let fileUrl = dir!.appendingPathComponent("koferoAuth.txt")
            do{
                try token.write(to: fileUrl, atomically: true, encoding: .utf8)
            }
            catch{
                fatalError("how did we get here?")
            }
        }
    }
}

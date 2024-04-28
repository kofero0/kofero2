//
//  Extension.swift
//  kofero
//
//  Created by Mitchell Drew on 17/8/23.
//

import Foundation
import UIKit
import SwiftUI
import presenter

typealias RestClosure = (Data?, URLResponse?, Error?) -> Void
typealias CompletionBlock = () -> Void

extension UIDevice {
       var modelName: String {
           var systemInfo = utsname()
           uname(&systemInfo)
           let machineMirror = Mirror(reflecting: systemInfo.machine)
           let identifier = machineMirror.children.reduce("") { identifier, element in
               guard let value = element.value as? Int8, value != 0 else { return identifier }
               return identifier + String(UnicodeScalar(UInt8(value)))
           }
           return identifier
       }
   }

extension UINavigationController {
    public func push<V: View>(_ view: V, animated: Bool = true) {
        let viewController = UIHostingController(rootView: view)
        pushViewController(viewController, animated: animated)
    }
    
    public func present<V: View>(_ view: V,
                                 animated: Bool = true,
                                 completion: (() -> Void)? = nil) {
        let viewController = UIHostingController(rootView: view)
        present(viewController, animated: animated, completion: completion)
    }
}


extension Date {
    func currentTimeMillis() -> Int64 {
        return Int64(self.timeIntervalSince1970 * 1000)
    }
}

extension Int32 {
    func toKotlinInt() -> KotlinInt {
        return KotlinInt(value: self)
    }
}

public protocol IUserDefaults {
    func set(_:Any?, forKey:String)
    func object(forKey:String) -> Any?
    func removeObject(forKey:String)
}

extension UserDefaults: IUserDefaults {}

public protocol RestTask {
  func resume()
  func cancel()
}

public protocol RestManager {
  func dataTask(with request: URLRequest, completionHandler: @escaping (Data?, URLResponse?, Error?) -> Void) -> URLSessionDataTask
}

extension KotlinException {
    convenience init(error:Error){
        self.init(message: error.localizedDescription)
    }
}

extension URLSession : RestManager{}
extension URLSessionDataTask : RestTask{}

public protocol IFileManager {
    var currentDirectoryPath: String {get}
    func contents(atPath:String) -> Data?
    func createFile(atPath: String, contents: Data?, attributes: [FileAttributeKey : Any]?) -> Bool
    func removeItem(atPath: String) throws
    func urls(for: FileManager.SearchPathDirectory, in: FileManager.SearchPathDomainMask) -> [URL]
    func fileExists(atPath: String) -> Bool
}

extension FileManager: IFileManager{
}


protocol HasApply { }

extension HasApply {
    func apply(closure:(Self) -> ()) -> Self {
        closure(self)
        return self
    }
}

extension Provider{
    func get(ids:[Int32]) async throws{
        var kIds = [KotlinInt]()
        for int in ids{
            kIds.append(int.toKotlinInt())
        }
        try await get(ids: kIds)
    }
}

@discardableResult
public func synchronized<T>(_ lock: AnyObject, closure:() -> T) -> T {
    objc_sync_enter(lock)
    defer { objc_sync_exit(lock) }
    return closure()
}

func convertBase64StringToImage (imageBase64String:String?) -> UIImage {
    if(imageBase64String == nil){
        return UIImage()
    }
    let imageData = Data(base64Encoded: imageBase64String!)
    let image = UIImage(data: imageData!)
    return image!
}


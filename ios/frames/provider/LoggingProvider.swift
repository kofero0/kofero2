//
//  LoggingProvider.swift
//  provider
//
//  Created by Mitchell Drew on 21/3/22.
//

import Foundation
import presenter

public class DebugLoggingProvider: LoggingProvider {
    public func log(level: ModelLevel, logTag: String, message: String) {
        print("\(level)::\(logTag):\(message)")
    }
}

public class ReleaseLoggingProvider: LoggingProvider {
    public func log(level: ModelLevel, logTag: String, message: String) {
        //NOOP
    }
}

//
//  StateLoggerImpl.swift
//  kofero
//
//  Created by Mitchell Drew on 24/1/24.
//

import Foundation
import presenter


//TODO: LOW PRIORITY
class StateLoggerImpl: StateLogger {
//    private let diskAccessor: DiskAccessor
//    private let mapper: StringMapper<[KotlinLong:ModelEvent]>
//
//    init(diskAccessor: DiskAccessor, mapper: StringMapper<[KotlinLong:ModelEvent]>){
//        self.diskAccessor = diskAccessor
//        self.mapper = mapper
//    }
    
    func getStateMap() -> [KotlinLong : ModelEvent] {
        return [KotlinLong:ModelEvent]()
    }
    
    func logState(unixTime: Int64, event: ModelEvent) {
        var map = getStateMap()
        map[KotlinLong(value: unixTime)] = event
        //diskAccessor.write(fileName: "statemap", json: )
    }
    
    
}

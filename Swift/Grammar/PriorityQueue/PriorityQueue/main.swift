//
//  main.swift
//  PriorityQueue
//
//  Created by 조윤영 on 2020/12/31.
//

import Foundation


func solution() {
    var pq = PriorityQueue<Int>()
    pq.push(5)
    pq.push(8)
    pq.push(1)
    
    while !pq.empty() {
        print(pq.top())
        pq.pop()
    }
}
//solution()

public struct PriorityQueue<T: Comparable> {
    internal var heap = Array<T>()
    public let ordered: (T, T) -> Bool
    public init(isUpper: Bool = true) {
        if isUpper { ordered = { $0 > $1} }
        else { ordered = {$0 < $1} }
    }
    
    public var count: Int { return heap.count }
    public func top() -> T? { return heap.first }
    public func empty() -> Bool { return heap.isEmpty }
    public mutating func push(_ element: T) {
        heap.append(element)
        swim(heap.count - 1)
    }
    public mutating func pop() {
            guard heap.count != 1 else {
                heap.removeFirst()
                return
            }
            heap.swapAt(0, heap.count - 1)
            heap.removeLast()
            sink(0)
        }
    public mutating func sink(_ index: Int) { //힙의 재구성
        var index = index
        
        while 2 * index + 1 < heap.count {
            var j = 2 * index + 1 //왼쪽 자식 노드
            if j + 1 < heap.count && ordered(heap[j], heap[j+1]) { j += 1}
            if !ordered(heap[index], heap[j]) { break }
            heap.swapAt(index, j)
            index = j
        }
    }
    public mutating func swim(_ index: Int) { //힙의 구성
        var index = index
        
        while index > 0 && ordered(heap[(index - 1) / 2], heap[index]) {
            heap.swapAt((index - 1) / 2, index)
            index = (index - 1) / 2
        }
    }
}

func test2() {
    var pq2 = PriorityQueue2<Int>(isUpper: false)
    pq2.push(3, 2)
    pq2.push(1,2)
    pq2.push(2,2)
    pq2.push(0,4)
    while !pq2.empty() {
        print(pq2.front)
        pq2.pop()
    }
}
test2()

//Dijkstra용 priority queue
//struct가 아니라 class로 해도 되네
public struct QueueItem <T: Equatable>: Comparable {
    let value: T
    var priority: Int
    
    init(_ value: T, _ priority: Int) {
        self.value = value
        self.priority = priority
    }
    
    public static func < (lhs: QueueItem<T>, rhs: QueueItem<T>) -> Bool {
        return lhs.priority < rhs.priority
    }
    
    public static func == (lhs: QueueItem<T>, rhs: QueueItem<T>) -> Bool {
        return lhs.priority == rhs.priority
    }
}

public struct PriorityQueue2<T: Equatable> {
    public var data = Array<QueueItem<T>>()
    public let ordered: (QueueItem<T>, QueueItem<T>) -> Bool
    public init(isUpper: Bool = true ) {
        if isUpper { ordered = { $0.priority > $1.priority }}
        else { ordered = { $0.priority < $1.priority }}
    }
    public func empty() -> Bool { return data.isEmpty }
    public var front: QueueItem<T>? { return data.first }
    public var count: Int { return data.count }
    public mutating func push(_ element: T, _ priority: Int ) {
        let newItem = QueueItem<T>(element, priority)
        data.append(newItem)
        swim(data.count - 1)
    }
    public mutating func pop() {
        if data.count == 1 {
            data.removeFirst()
            return
        }
        data.swapAt(0, data.count - 1) //(*)
        data.removeLast()
        sink(0)
    }
    
    func parent(_ children: Int) -> Int { return (children - 1) / 2 }
    func children(_ parent: Int) -> Int { return parent * 2 + 1 }
    //자식이랑 부모간의 대소 비교
    public mutating func swim(_ index: Int ) {
        var index = index
        while 0 < index && ordered(data[parent(index)], data[index]) {
            data.swapAt(parent(index), index)
            index = parent(index)
        }
    }
    
    public mutating func sink(_ index: Int) {
        var index = index
        var j = children(index)
        while j < data.count {
        if j + 1 < data.count && ordered(data[j], data[j+1]) {  j += 1 }
        if !ordered(data[index], data[j]) { break }
        data.swapAt(index, j)
        index = j
        }
    }
}



//public struct QueueItem<T>: Comparable {
//    
//    public var value: (y: Int, x: Int)
//    public var priority: Int
//    
//    public init(value: (y: Int, x: Int), priority: Int) {
//        self.value = value
//        self.priority = priority
//    }
//    
//    public static func < (lhs: QueueItem<T>, rhs: QueueItem<T>) -> Bool {
//        return lhs.priority < rhs.priority
//    }
//    public static func == (lhs: QueueItem<T>, rhs: QueueItem<T>) -> Bool {
//        return lhs.priority == rhs.priority
//    }
//}
//public struct PriorityQueue<T: Equatable> {
//    public let ordered: (QueueItem<T>, QueueItem<T>) -> Bool
//    public var data = Array<QueueItem<T>>()
//    public init(isUpper: Bool = true) {
//        if isUpper { ordered = { $0.priority > $1.priority } }
//        else { ordered = { $0.priority < $1.priority }}
//    }
//    public func front() -> QueueItem<T>? { return data.first }
//    public var count: Int { return data.count }
//    public var isEmpty: Bool { return data.isEmpty }
//    
//    public mutating func push(_ element: QueueItem<T>) {
//        
//        data.append(element)
//        swim(data.count - 1)
//    }
//    public mutating func pop() {
//        if data.count == 1 {
//            data.removeFirst()
//            return
//        }
//        data.swapAt(0, data.count - 1)
//        data.removeLast()
//        sink(0)
//    }
//    
//    func parent(_ index: Int) -> Int { return (index - 1) / 2 }
//    func child(_ index: Int) -> Int { return index * 2 + 1 }
//    //부모를 찾아서
//    public mutating func swim(_ index: Int) {
//        var index = index
//        while index > 0 && ordered(data[parent(index)], data[index]) {
//            data.swapAt(index, parent(index))
//            index = parent(index)
//        }
//    }
//    
//    //자식을 찾아서
//    public mutating func sink(_ index: Int) {
//        var index = index
//        var j = child(index)
//        while j < data.count {
//            if j + 1 < data.count && ordered(data[j], data[j + 1]) { j += 1 }
//            if !ordered(data[index], data[j]) { break }
//            data.swapAt(index, j)
//            index = j
//        }
//    }
//}

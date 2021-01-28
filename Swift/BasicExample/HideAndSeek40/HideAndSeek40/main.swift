//
//  main.swift
//  HideAndSeek40
//
//  Created by 조윤영 on 2021/01/28.
//

import Foundation

var N: Int = 0
var M: Int = 0
var rooms = [[Int]]()
let INF = 20001

func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]
    rooms = [[Int]](repeating: [Int](repeating: INF, count: N+1), count: N+1)
    (0..<M).forEach { _ in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))!}
        let A = inputList2[0]
        let B = inputList2[1]
        rooms[A][B] = 1
        rooms[B][A] = 1
    }
}

//1번 헛간으로부터 다른 모든 헛간에 대해 최단거리를 탐색해야 하므로
//Dijkstra
func solution() {
    var costs = [Int](repeating: INF, count: N+1)
    var pq = PriorityQueue<QueueItem<(value: Int, priority: Int)>>()
    pq.push(QueueItem(value: 1, priority: 0))
    costs[1] = 0
    
    while !pq.isEmpty {
        let currentRoom = pq.front()!.value
        let cost = pq.front()!.priority
        pq.pop()
        
        if costs[currentRoom] < cost { continue }
        (1...N).forEach { nextRoom in
            let nextCost = cost + rooms[currentRoom][nextRoom]
            if nextCost < costs[nextRoom] {
                costs[nextRoom] = nextCost
                pq.push(QueueItem(value: nextRoom, priority: nextCost))
            }
        }
    }
    
    var maxCost = 0
    var answer_list = [Int]()
    (1...N).forEach { i in
        if maxCost < costs[i] {
            maxCost = costs[i]
            answer_list.removeAll()
            answer_list.append(i)
        } else if maxCost == costs[i] { answer_list.append(i) }
    }
    
    print("\(answer_list[0]) \(maxCost) \(answer_list.count)")
}

input()
solution()

public struct QueueItem<T>: Comparable {
    
    public var value: Int
    public var priority: Int
    
    public init(value: Int, priority: Int) {
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
public struct PriorityQueue<T: Equatable> {
    public let ordered: (QueueItem<T>, QueueItem<T>) -> Bool
    public var data = Array<QueueItem<T>>()
    public init(isUpper: Bool = true) {
        if isUpper { ordered = { $0.priority > $1.priority } }
        else { ordered = { $0.priority < $1.priority }}
    }
    public func front() -> QueueItem<T>? { return data.first }
    public var count: Int { return data.count }
    public var isEmpty: Bool { return data.isEmpty }
    
    public mutating func push(_ element: QueueItem<T>) {
        
        data.append(element)
        swim(data.count - 1)
    }
    public mutating func pop() {
        if data.count == 1 {
            data.removeFirst()
            return
        }
        data.swapAt(0, data.count - 1)
        data.removeLast()
        sink(0)
    }
    
    func parent(_ index: Int) -> Int { return (index - 1) / 2 }
    func child(_ index: Int) -> Int { return index * 2 + 1 }
    //부모를 찾아서
    public mutating func swim(_ index: Int) {
        var index = index
        while index > 0 && ordered(data[parent(index)], data[index]) {
            data.swapAt(index, parent(index))
            index = parent(index)
        }
    }
    
    //자식을 찾아서
    public mutating func sink(_ index: Int) {
        var index = index
        var j = child(index)
        while j < data.count {
            if j + 1 < data.count && ordered(data[j], data[j + 1]) { j += 1 }
            if !ordered(data[index], data[j]) { break }
            data.swapAt(index, j)
            index = j
        }
    }
}


// 6 7
// 3 6
// 4 3
// 3 2
// 1 3
// 1 2
// 2 4
// 5 2

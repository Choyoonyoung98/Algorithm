//
//  main.swift
//  MarsExploration39
//
//  Created by 조윤영 on 2021/01/27.
//

import Foundation
var moveDir: [(y: Int, x: Int)] = [(-1,0),(1,0),(0,-1),(0,1)]
var T: Int = 0
var N: Int = 0
let INF = 1000001
var mars = [[Int]]()
func input() {
    T = Int(String(readLine()!))!
    (0..<T).forEach { _ in
        N = Int(String(readLine()!))!
        mars = [[Int]]()
        (0..<N).forEach { i in
            let inputList = readLine()!.split(separator: " ").map{ Int(String($0))! }
            mars.append(inputList)
        }
        
        print(solution())
    }
}

func isAvailable(_ y: Int, _ x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < N { return true}
    return false
}
func solution() -> Int {
    var costs =  [[Int]](repeating: [Int](repeating: INF, count: N), count: N)
    var pq = PriorityQueue<QueueItem<(value: (y: Int, x: Int), priority: Int)>>()

    pq.push(QueueItem(value: (y: 0, x: 0), priority: mars[0][0]))
    while !pq.isEmpty {
        let currentY = pq.front()!.value.y
        let currentX = pq.front()!.value.x
        let currentCost = pq.front()!.priority
        pq.pop()
        
        if costs[currentY][currentX] < currentCost { continue }
        (0..<4).forEach{ d in
            let nextY = currentY + moveDir[d].y
            let nextX = currentX + moveDir[d].x
            if isAvailable(nextY, nextX) {
                let nextCost = currentCost + mars[nextY][nextX]
                if costs[nextY][nextX] > nextCost {
                    costs[nextY][nextX] = nextCost
                    pq.push(QueueItem(value: (y: nextY, x: nextX), priority: nextCost))
                }
            }
        }
    }
    
    return costs[N-1][N-1]
}

input()

public struct QueueItem<T>: Comparable {
    
    public var value: (y: Int, x: Int)
    public var priority: Int
    
    public init(value: (y: Int, x: Int), priority: Int) {
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

//3
//3
//5 5 4
//3 9 1
//3 2 7
//5
//3 7 2 0 1
//2 8 0 9 1
//1 2 1 8 1
//9 8 9 2 0
//3 6 5 1 5
//7
//9 0 5 1 1 5 3
//4 1 2 1 6 5 3
//0 7 6 1 6 8 5
//1 1 7 8 3 2 3
//9 4 0 7 6 4 1
//5 8 3 2 4 8 3
//7 4 8 4 8 3 4


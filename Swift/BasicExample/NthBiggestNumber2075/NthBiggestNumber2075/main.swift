//
//  main.swift
//  NthBiggestNumber2075
//
//  Created by 조윤영 on 2021/02/08.
//

import Foundation

var N: Int = 0
var board = [[Int]]()

func solution() -> Int {
    var pq = PriorityQueue<Int>()
    N = Int(String(readLine()!))!
    (0..<N).forEach{ _ in
        let input: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        (0..<N).forEach{ i in
            if pq.count == N {
                if pq.top()! < input[i] {
                    pq.pop()
                    pq.push(input[i])
                }
            }
            else { pq.push(input[i])}
        }
    }
    return pq.top()!
}

print(solution())

public struct PriorityQueue<T: Comparable> {
    internal var data = Array<T>()
    public let ordered: (T, T) -> Bool
    public init(isUpper: Bool = true) {
        if(isUpper) { ordered = { $0 > $1}}
        else { ordered = { $0 < $1} }
    }
    
    public var count: Int { return data.count }
    public func top() -> T? { return data.first }
    public func empty() -> Bool { return data.isEmpty }
    public mutating func push(_ element: T) {
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
    
    func parent(_ children: Int) -> Int { return (children - 1) / 2 }
    func children(_ parent: Int) -> Int { return parent * 2 + 1 }
    
    //parent
    public mutating func swim(_ index: Int) {
        var index = index
        while index > 0 && ordered(data[parent(index)], data[index]) {
            data.swapAt(parent(index), index)
            index = parent(index)
        }
    }
    
    //child
    public mutating func sink(_ index: Int) {
        var index = index
        var j = children(index)
        while j < data.count {
            if j + 1 < data.count && ordered(data[j], data[j+1]) { j += 1 }
            if !ordered(data[index], data[j]) { break }
            data.swapAt(index, j)
            index = j
        }
    }
 }

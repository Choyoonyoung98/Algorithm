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
    }
}
solution()

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

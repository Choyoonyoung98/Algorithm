//
//  main.swift
//  PriorityQueue
//
//  Created by 조윤영 on 2020/12/31.
//

import Foundation


func solution() {
    var pq: PriorityQueue<Int>()
    pq.push(5)
    pq.push(8)
    pq.push(1)
    
    while(!pq.isEmpty) {
        print(pq.top())
        pq.pop()
    }
    
    var upperPQ: PriorityQueue<Int>()
    upperPQ.push(5)
    upperPQ.push(8)
    upperPQ.push(1)
    
    while(!upperPQ.isEmpty) {
        print(upperPQ.top())
        upperPQ.pop()
    }
}


public struct PriorityQueue<T: Comparable> {
    private var heap = [T]()
    private let ordered:(T, T) -> Bool //let
    public init(ascending: Bool = false) {
        if !ascending { ordered = { $0 < $1 }}
        else { ordered = {$0 > $1 }}
    }
    
    public var isEmpty: Bool { return heap.isEmpty }
    public func top() -> T? { return heap.first }
    
    public mutating func push(_ element: T) {
        heap.append(element)
        swim(heap.count - 1)//
    }
    
    public mutating func pop() {
        guard heap.count == 1 else {
            heap.removeFirst()
            return
        }
        heap.swapAt(0, heap.count - 1)
        heap.removeLast()
        sink(0)//
    }
    
    private mutating func swim(_ index: Int) {
        var index = index
        
        while 2 * index + 1 < heap.count {
            var j = index * 2 + 1 //자식
            if j < heap.count - 1 && ordered(heap[j], heap[j+1]) { j += 1 } //왼쪽 자식 노드, 오른쪽 자식 노드 대소 비교
            if !ordered(heap[index], heap[j]) { break }
            heap.swapAt(index, j)
            index = j
        }
    }
    
    private mutating func sink(_ index: Int) {
        var index = index
        
        while index > 0 && ordered(heap[(index - 1) / 2], heap[index]) {
            heap.swapAt((index - 1) / 2, index)
            index = (index - 1) / 2
        }
    }
}


//
//  main.swift
//  Queue
//
//  Created by 조윤영 on 2020/12/29.
//

import Foundation

public func solution() {
    var q = Queue<Int>()
    q.push(1)
    q.push(2)
    q.push(3)
    while(!q.isEmpty()) {
        print(q.top()!)
        q.pop()
    }
}
solution()

public struct Queue<T> {
    public init() { }
    
    internal var data = Array<T>()
    
    public func top() -> T? {
        return data.first
    }
    
    public mutating func push(_ element: T) {
        data.append(element)
    }
    
    public mutating func pop() {
        data.removeFirst()
    }
    
    public mutating func clear() {
        data.removeAll()
    }
    
    public func isEmpty() -> Bool {
        return data.isEmpty
    }
    
    public func count() -> Int {
        return data.count
    }
}

public struct prioritQueue<T> {
    internal var heap = Heap<T>()
    public init(sort: @escaping (T, T) -> Bool) {
        heap = Heap(sort: sort)
    }
    
    public func top() -> T{
        
    }
    
    public func push(_ element: T) {
        
    }
    
    public func pop()  {
        
    }
    public func isEmpty() -> Bool {
        return data.isEmpty
    }
    
    
}

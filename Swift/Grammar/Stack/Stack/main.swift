//
//  main.swift
//  Stack
//
//  Created by 조윤영 on 2021/01/02.
//

import Foundation

func solution() {
    var s = Stack<Int>()
    s.push(3)
    s.push(5)
    s.push(1)
    
    while !s.isEmpty {
        print(s.top())
        s.pop()
    }
}

solution()

public struct Stack<T> {
    public init() { }
    internal var data = Array<T>()
    public var isEmpty: Bool { data.isEmpty }
    public func top() -> T? { return data.last }
    public var count: Int { return data.count }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeLast() }
}



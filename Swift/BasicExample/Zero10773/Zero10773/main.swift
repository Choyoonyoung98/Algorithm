//
//  main.swift
//  Zero10773
//
//  Created by 조윤영 on 2021/01/02.
//

import Foundation
var s = Stack<Int>()

public func input() {
    if let K: Int = Int(readLine()!) {
        for _ in 0..<K {
            if let n: Int = Int(readLine()!) {
                checkIsCorrect(n)
            }
        }
    }
    print(solution())
}

public func checkIsCorrect(_ n: Int) {
    if(n == 0) {
        s.pop()
    } else { s.push(n) }
}

public func solution() -> Int {
    var answer: Int = 0
    while !s.isEmpty {
        answer += s.top()!
        s.pop()
    }
    
    return answer
}

input()
solution()

public struct Stack<T> {
    public init() { }
    internal var data = Array<T>()
    public var isEmpty: Bool { data.isEmpty }
    public func top() -> T? { return data.last }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeLast() }
    
}

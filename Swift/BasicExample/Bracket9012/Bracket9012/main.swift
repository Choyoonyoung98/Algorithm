//
//  main.swift
//  Bracket9012
//
//  Created by 조윤영 on 2021/01/02.
//

import Foundation

func input() {
    if let T: Int = Int(readLine()!) {
        for _ in 0..<T {
            if let word: String = readLine() {
                print(solution(word))
            }
        }
    }
    
}

func solution(_ word: String) -> String {
    var s = Stack<Character>()
    for w in word {
        if w == ")" { //char이 아닌 string으로 받는다
            guard !s.isEmpty else { return "NO" }
            s.pop()
        } else {
            s.push("(")
        }
    }
    
    if s.count != 0 { return "NO" }
    else { return "YES" }
}

input()

public struct Stack<T> {
    public init() { }
    internal var data = Array<T>()
    
    public var isEmpty: Bool { return data.isEmpty }
    public var count: Int { return data.count }
    public func top() -> T? { return data.last }
    
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeLast() }
    
}

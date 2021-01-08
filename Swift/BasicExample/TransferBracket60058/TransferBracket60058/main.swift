//
//  main.swift
//  TransferBracket60058
//
//  Created by 조윤영 on 2021/01/08.
//
import Foundation

func checkIsBalanced(_ u: String) -> Bool {
    var s = Stack<Character>()
    for c in u {
        if c == ")" {
            guard !s.isEmpty else { return false }
            s.pop()
        } else { s.push(")") }
    }
    
    if !s.isEmpty { return false }
    
    return true
}

func makeUCorrect(_ u: String, _ v: String) -> String {
    var result: String = "(";
    result = result + solution(v)
    result += ")"
    
    var cpy_u: String = ""
    if (u.count == 2) { cpy_u = "" }
    else {
        let range = u.index(u.startIndex, offsetBy: 1) ... u.index(u.endIndex, offsetBy: -2)
        cpy_u = String(u[range])
    }
    var temp: String = ""
    for c in cpy_u {
        if c == "(" { temp += ")" }
        else { temp += "(" }
    }
    
    result += temp
    
    print(":\(result)")
    return result
}

func solution(_ p:String) -> String {
    var leftCnt: Int = 0
    var rightCnt: Int = 0
    var u: String = ""
    
    for (index, s) in p.enumerated() {
        print(s)
        if s == "(" { leftCnt += 1 }
        else { rightCnt += 1 }
        u += String(s)
        
        if leftCnt != 0 && leftCnt == rightCnt {
            print(u)
            var v: String = ""
            if(index != p.count - 1) {
                let range = p.index(p.startIndex, offsetBy: index + 1) ... p.index(p.endIndex, offsetBy: -1)
                v = String(p[range])
            }
            
            if(checkIsBalanced(u)) { return u + solution(v) }
            else { return makeUCorrect(u, v) }
        }
    }
    
    return ""
    
}

print(solution("()))((()"))

public struct Stack<T> {
    internal var data = Array<T>()
    public init() { }
    
    public var size: Int {
        return data.count
    }
    public var top: T? {
        return data.last
    }
    public var isEmpty: Bool {
        return data.isEmpty
    }
    public mutating func push(_ element: T) {
        data.append(element)
    }
    public mutating func pop() {
        data.removeLast()
    }
    
}

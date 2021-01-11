//
//  main.swift
//  NandM_3
//
//  Created by 조윤영 on 2021/01/11.
//
/*
 1. joined(seperator:" ") 써서 print 할 때
 0.0004349946975708008

 2.forEach문으로 출력할 때
 0.0007239580154418945
 */
import Foundation

var N: Int = 0
var M: Int = 0
var list = [String]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    M = inputList[1]
}

func DFS(_ cnt: Int) {
    if cnt == M {
        print(list.joined(separator: " "))
        return
    }
    
    for i in 1...N {
        list.append(String(i))
        DFS(cnt+1)
        list.removeLast()
    }
}

func solution() {
    DFS(0)
}

public func measureTime(_ closure: () -> ()) -> TimeInterval {
    let startDate = Date()
    closure()
    return Date().timeIntervalSince(startDate)
}

input()
print(measureTime {
    solution()
})


//
//  main.swift
//  NandM_1
//
//  Created by 조윤영 on 2021/01/11.
//

import Foundation
var N: Int = 0
var M: Int = 0
var answer: Int = 0
var visited =  [Bool](repeating: false, count: 10)
var list = [Int]()
func input() {
    var inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    M = inputList[1]
}

func DFS( _ cnt: Int) {
    if cnt == M {
        list.forEach { (l) in
            print(l, terminator: " ")
        }
        print()
        return
    }
    
    for i in 1...N {
        guard !visited[i] else { continue }
        visited[i] = true
        list.append(i)
        DFS(cnt+1)
        visited[i] = false
        list.removeLast()
    }
}

func solution() {
    DFS(0)
}

input()
solution()

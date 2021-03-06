//
//  main.swift
//  NandM_5
//
//  Created by 조윤영 on 2021/01/11.
//

import Foundation

func input() {
    let inputList1: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    let N = inputList1[0]
    let M = inputList1[1]
    var list: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    list.sort()

    solution(list, N, M)
}

var answer_list = [String]()
var visited = [Bool](repeating: false, count: 10)
func DFS(_ list: [Int], _ N: Int, _ M: Int, _ cnt: Int) {
    if cnt == M {
        print(answer_list.joined(separator: " "))
        return
    }
    
    for i in 0..<N {
        guard !visited[i] else { continue }
        visited[i] = true
        answer_list.append(String(list[i]))
        DFS(list, N, M, cnt+1)
        visited[i] = false
        answer_list.removeLast()
    }
}

func solution(_ list: [Int], _ N: Int, _ M: Int) {
    DFS(list, N, M, 0)
}

input()

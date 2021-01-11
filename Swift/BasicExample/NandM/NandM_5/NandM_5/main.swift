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
    let list: [String] = readLine()!.split(separator: " ").map{ String($0) }

    solution(list, N, M)
}

var answer_list = [String]()
var numb_list = [String]()
var visited = [Bool](repeating: false, count: 10)
func DFS(_ list: [String], _ N: Int, _ M: Int, _ cnt: Int) {
    if cnt == M {
        let answer: String = numb_list.joined(separator: " ")
        answer_list.append(answer)
        return
    }
    
    for i in 0..<N {
        guard !visited[i] else { continue }
        visited[i] = true
        numb_list.append(list[i])
        DFS(list, N, M, cnt+1)
        visited[i] = false
        numb_list.removeLast()
    }
}

func solution(_ list: [String], _ N: Int, _ M: Int) {
    DFS(list, N, M, 0)
    answer_list.sort()
    print(answer_list.joined(separator: "\n"))
}

input()

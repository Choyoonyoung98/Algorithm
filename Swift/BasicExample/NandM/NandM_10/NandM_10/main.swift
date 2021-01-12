//
//  main.swift
//  NandM_10
//
//  Created by 조윤영 on 2021/01/12.
//

import Foundation

func input() {
    let input: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    let N = input[0]
    let M = input[1]
    
    var list: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    list.sort()
    solution(N, M, list)
}

var answer_list = [String]()
var dict = Dictionary<[String], Bool>()
func DFS(_ N: Int, _ M: Int, _ list: [Int], _ index: Int, _ cnt: Int) {
    if cnt == M {
        if let _ = dict[answer_list] { return }
        dict.updateValue(true, forKey: answer_list)
        print(answer_list.joined(separator: " "))
        return
    }
    
    guard index <= N else { return }
    
    for i in index..<N {
        answer_list.append(String(list[i]))
        DFS(N, M, list, i+1, cnt+1)
        answer_list.removeLast()
    }
    
}

func solution(_ N: Int, _ M: Int, _ list: [Int]) {
    DFS(N, M, list, 0, 0)
}

input()

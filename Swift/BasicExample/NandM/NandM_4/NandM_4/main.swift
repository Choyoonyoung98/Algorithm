//
//  main.swift
//  NandM_4
//
//  Created by 조윤영 on 2021/01/11.
//

import Foundation

func input(){
    let inputList: [Int] = readLine()!.split(separator:" ").map{ Int($0)! }
    let N: Int = inputList[0]
    let M: Int = inputList[1]
    solution(N, M)
}

var list = [String]()
func DFS(_ N: Int, _ M: Int, _ index: Int, _ cnt: Int) {
    if cnt == M {
        print(list.joined(separator:" "))
        return
    }
    
    for i in index...N {
        list.append(String(i))
        DFS(N, M, i, cnt+1)
        list.removeLast()
    }
}
func solution(_ N: Int, _ M: Int) {
    DFS(N, M, 1, 0)
}


input()



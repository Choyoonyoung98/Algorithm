//
//  main.swift
//  NandM_2
//
//  Created by 조윤영 on 2021/01/11.
//

import Foundation

var N: Int = 0
var M: Int = 0
var list =  [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    M = inputList[1]
}

func dfs(_ index: Int, _ cnt: Int) {
    
    if cnt == M {
        list.forEach { (l) in
            print(l, terminator: " ")
        }
        print()
    }
    guard  index <= N else { return }
    
    for i in index...N {
        list.append(i)
        dfs(i+1, cnt+1)
        list.removeLast()
    }
}

func solution() {
    dfs(1, 0)
}

input()
solution()

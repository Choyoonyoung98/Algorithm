//
//  main.swift
//  CuttingTree2805
//
//  Created by 조윤영 on 2021/01/18.
//

import Foundation

var N: Int = 0
var M: Int = 0
var tree_list = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").compactMap{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]
    tree_list = readLine()!.split(separator: " ").compactMap{ Int(String($0))! }
}

func solution() -> Int {
    tree_list.sort()
    var answer: Int = 0
    var minH: Int = 0
    var maxH: Int = tree_list[tree_list.count - 1] - 1 //(*)
    var mid: Int = (minH + maxH) / 2
    
    while maxH >= minH {
        mid = (minH + maxH) / 2
        let h = mid
        var sum = 0
        for i in (0..<N).reversed() {
            let diff = tree_list[i] - h
            guard diff > 0 else { break }
            sum += diff
        }

        if sum >= M {
            answer = max(answer, mid)
            minH = mid + 1 //(*)
        }
        else { maxH = mid - 1} //(*)
    }
    
    return answer
}

input()
print(solution())


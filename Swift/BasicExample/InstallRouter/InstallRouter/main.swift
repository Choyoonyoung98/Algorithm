//
//  main.swift
//  InstallRouter
//
//  Created by 조윤영 on 2021/01/18.
//

import Foundation

var N: Int = 0
var C: Int = 0
var houses = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    C = inputList[1]
    (0..<N).forEach { _ in
        let x = Int(readLine()!)!
        houses.append(x)
    }
}

func solution() -> Int{
    var answer: Int = -1
    houses.sort()
    var minDist: Int = 1
    var maxDist: Int = houses[houses.count - 1] - houses[0]
    var cnt = 0
    while minDist <= maxDist {
        cnt = 0
        var mid = (minDist + maxDist) / 2
        var prev = houses[0]
        cnt += 1
        
        (1..<N).forEach { i in
            if houses[i] - prev >= mid {
                prev = houses[i]
                cnt += 1
            }
        }
        
        if cnt < C { maxDist = mid - 1}
        else {
            answer = max(answer, mid)
            minDist = mid + 1
        }
    }
    return answer
}

input()
print(solution())

//1 2 4 8 9
//1 4 9
//1 2 4 9
//1 4 8 9

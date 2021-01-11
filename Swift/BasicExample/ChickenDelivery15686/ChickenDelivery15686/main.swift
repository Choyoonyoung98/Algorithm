//
//  main.swift
//  ChickenDelivery15686
//
//  Created by 조윤영 on 2020/12/31.
//

import Foundation

var N: Int = 0
var M: Int = 0
var map = [[Int]]()
var houses = [(y: Int, x: Int)]()
var chickens = [(y: Int, x: Int)]()
var order = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    M = inputList[1]
    map = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)
    for i in 0..<N {
        let mapInputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
        for j in 0..<N {
            if mapInputList[j] == 1 { houses.append((y: i,x:  j)) }
            else if mapInputList[j] == 2 { chickens.append((y: i, x:  j)) }
        }
    }
}

func getChickenDist() -> Int {
    var result = 0
    houses.forEach { house in
        var dist = Int.max
        order.forEach { o in
            let diffY = abs(chickens[o].y - house.y)
            let dffX = abs(chickens[o].x - house.x)
            let diffSum = diffY + dffX
            dist = dist > diffSum ? diffSum : dist
        }
        result += dist
    }
    
    return result
}

var answer: Int = Int.max
func DFS(_ cnt: Int) {
    if cnt == M {
        answer = min(answer, getChickenDist())
        return
    }
    
    var idx = order.count == 0 ? 0 : order.last! + 1

    while idx < chickens.count {
        order.append(idx)
        DFS(cnt+1)
        order.removeLast()
        idx += 1
    }
}

func solution() {
    DFS(0)
    print(answer)
}

input()
solution()

//
//  main.swift
//  TravelPlan41
//
//  Created by 조윤영 on 2021/01/30.
//

import Foundation

var N: Int = 0
var M: Int = 0
var roads = [[Int]]()
var plans = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]
    (0..<N).forEach{ i in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        roads.append(inputList2)
    }
    
    plans = readLine()!.split(separator: " ").map{ Int(String($0))! }
}

var parent = [Int]()
func findParent(_ x: Int ) -> Int {
    if x == parent[x] { return x }
    parent[x] = findParent(parent[x])
    return parent[x]
}
func unionParent(a: Int, b: Int) {
    let a = findParent(a)
    let b = findParent(b)
    
    if a < b { parent[b] = a }
    else { parent[a] = b }
}
func solution() -> String {
    (0..<N).forEach{ i in parent.append(i)}
    (0..<N).forEach{ i in
        (0..<N).forEach{ j in
            if roads[i][j] == 1 { unionParent(a: i, b: j) }
        }
    }
    
    for i in 0..<M-1 {
        if findParent(plans[i] - 1) != findParent(plans[i+1]-1) { return "NO" }
    }
    return "YES"
}
input()
print(solution())


/*
 5 4
 0 1 0 1 1
 1 0 1 1 0
 0 1 0 0 0
 1 1 0 0 0
 1 0 0 0 0
 2 3 4 3
 */

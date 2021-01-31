//
//  main.swift
//  DarkStreet43
//
//  Created by 조윤영 on 2021/01/31.
//

import Foundation
var N: Int = 0
var M: Int = 0
var roads = [(x: Int, y: Int, z: Int)]()
var parent = [Int]()
func input() {
    let inputList1: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N  = inputList1[0]
    M = inputList1[1]
    
    parent = [Int](repeating: 0, count: N+1)
    (0..<M).forEach{ _ in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        roads.append((x: inputList2[0], y: inputList2[1], z: inputList2[2]))
    }
}

func findParent(_ x: Int) -> Int {
    if x == parent[x] { return x }
    parent[x] = findParent(parent[x])
    return parent[x]
}

func unionParent(_ a: Int, _ b: Int) {
    let a = findParent(a)
    let b = findParent(b)
    
    if a < b { parent[b] = a }
    else { parent[a] = b }
}

func solution() -> Int {
    var sum = 0
    var cost = 0
    
    //(*)
    roads.sort {
        if $0.z < $1.z { return $0 > $1 }
        else { return $0 < $1 }
    }
    (1...N).forEach{ i in parent[i] = i }
    for road in roads {
        sum += road.z
        if findParent(road.x) != findParent(road.y) {
            unionParent(road.x, road.y)
            cost += road.z
        }
    }
    
    return sum - cost
    
}

input()
print(solution())

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
*/

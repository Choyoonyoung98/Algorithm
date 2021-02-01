//
//  main.swift
//  PlanetTunnel2887
//
//  Created by 조윤영 on 2021/01/31.
//

import Foundation
var N: Int = 0
var planetX = [(index: Int, x: Int)]()
var planetY = [(index: Int, y: Int)]()
var planetZ = [(index: Int, z: Int)]()
var parent = [Int]()
func input() {
    N = Int(String(readLine()!))!
    parent = [Int](repeating: 0, count: N)
    (0..<N).forEach{ i in
        let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        planetX.append((index: i, x: inputList[0]))
        planetY.append((index: i, y: inputList[1]))
        planetZ.append((index: i, z: inputList[2]))
    }
}

func sortPlanetPos() {
    planetX.sort{ return $0.x < $1.x }
    planetY.sort{ return $0.y < $1.y }
    planetZ.sort{ return $0.z < $1.z }
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
    var answer = 0
    (0..<N).forEach{ i in parent[i] = i }
    sortPlanetPos()
    var edges = [(cost: Int, a: Int, b: Int)]()
    (0..<N-1).forEach{ i in
        edges.append((cost: planetX[i+1].x - planetX[i].x, a: planetX[i+1].index, b: planetX[i].index))
        edges.append((cost: planetY[i+1].y - planetY[i].y, a: planetY[i+1].index, b: planetY[i].index))
        edges.append((cost: planetZ[i+1].z - planetZ[i].z, a: planetZ[i+1].index, b: planetZ[i].index))
    }
    
    edges.sort{ return $0.cost < $1.cost }

    (0..<edges.count).forEach{ i in
        if findParent(edges[i].a) != findParent(edges[i].b) {
            unionParent(edges[i].a, edges[i].b)
            answer += (edges[i].cost)
        }
    }
    
    return answer
}

input()
print(solution())

/*
5
11 -15 -15
14 -5 -15
-1 -1 -5
10 -4 -1
19 -4 19
 */


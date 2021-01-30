//
//  main.swift
//  Gate42
//
//  Created by 조윤영 on 2021/01/30.
//

import Foundation

var G: Int = 0
var P: Int = 0
var parent = [Int]()
var docking_possibility = [Int]()
func input() {
    G = Int(String(readLine()!))!
    P = Int(String(readLine()!))!
    parent = [Int](repeating: 0, count: G+1)
    (0..<P).forEach{ _ in
        let x = Int(String(readLine()!))!
        docking_possibility.append(x)
    }
}

func findParent(_ x: Int) -> Int {
    if x == parent[x] { return x } //(*)
    parent[x] = findParent(parent[x])
    return parent[x]
}

func unionParent(a: Int, b: Int) {
    var a = findParent(a)
    var b = findParent(b)
    
    if a < b { parent[b] = a }
    else { parent[a] = b }
}

func solution() -> Int{
    var answer = 0
    for i in 1...G { parent[i] = i } //(*)
    for dp in docking_possibility {
        
        let root = findParent(dp)
        if root == 0 { break }
        unionParent(a: root, b: root-1)
        answer += 1
    }
    
    return answer
}

input()
print(solution())


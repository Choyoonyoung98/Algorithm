//
//  main.swift
//  Antenna18310
//
//  Created by 조윤영 on 2020/12/31.
//

import Foundation

var N: Int = 0
var houses = [Int]()
func input() {
    if let n = readLine() {
        N = Int(n)!
    }
    houses = readLine()!.split(separator: " ").map{ Int($0)! }
}

func solution() -> Int {
    houses.sort()
    return houses[(N-1)/2]
}

input()
print(solution())

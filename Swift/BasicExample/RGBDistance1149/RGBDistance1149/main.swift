//
//  main.swift
//  RGBDistance1149
//
//  Created by 조윤영 on 2021/01/24.
//

import Foundation

var N: Int = 0
var costs = [Int]()
var houses = [[Int]]()
func solution() {
    N = Int(readLine()!)!
    costs = [Int](repeating: 0, count: 3)
    houses = [[Int]](repeating: [Int](repeating: 0, count: 3), count: N+1)
    (1...N).forEach{ i in
        let cost = readLine()!.split(separator: " ").map{ Int(String($0))! }
        
        houses[i][0] = min(houses[i-1][1], houses[i-1][2]) +  cost[0]
        houses[i][1] = min(houses[i-1][0], houses[i-1][2]) + cost[1]
        houses[i][2] = min(houses[i-1][0], houses[i-1][1]) + cost[2]
    }
    
    print(min(min(houses[N][0], houses[N][1]), houses[N][2]))
}

solution()


//
//  main.swift
//  2NTiling
//
//  Created by 조윤영 on 2021/01/22.
//

import Foundation

var N: Int = 0
func input() {
    N = Int(readLine()!)!
}

func solution() -> Int {
    var dp = [Int](repeating: 0, count: 1001)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    
    if N <= 2 { return dp[N] }
    (3...N).forEach { i in
       dp[i] = dp[i-1] + dp[i-2]
        dp[i] %= 10007
    }
    
    return dp[N]
}

input()
print(solution())

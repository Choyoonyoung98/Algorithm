//
//  main.swift
//  UglyNumber35
//
//  Created by 조윤영 on 2021/01/26.
//

import Foundation
let MAX_SIZE = 1001
var dp = [Int](repeating: 0, count: MAX_SIZE)

public func min(_ x: Int, _ y: Int, _ z: Int) -> Int {
    return min(x, min(y,z))
}
public func solution(_ N: Int ) -> Int {
    var i2 = 0
    var i3 = 0
    var i5 = 0
    var next2 = 2
    var next3 = 3
    var next5 = 5
    
    dp[0] = 1
    for i in 1..<N {
        dp[i] = min(next2, next3, next5)
        
        if dp[i] == next2 {
            i2 += 1
            next2 = dp[i2] * 2
        }
        if dp[i] == next3 {
            i3 += 1
            next3 = dp[i3] * 3
        }
        if dp[i] == next5 {
            i5 += 1
            next5 = dp[i5] * 5
        }
    }
    
    return dp[N-1]
}

print(solution(10))

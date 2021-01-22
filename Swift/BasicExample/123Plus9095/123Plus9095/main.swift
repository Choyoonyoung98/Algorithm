//
//  main.swift
//  123Plus9095
//
//  Created by 조윤영 on 2021/01/22.
//

import Foundation

var T: Int = 0
var numbers = [Int]()

func input() {
    T = Int(readLine()!)!
    (0..<T).forEach{ i in
        let n = Int(readLine()!)!
        numbers.append(n)
    }
}
func solution()  {
    var dp = [Int]()
    for n in numbers {
        dp = [Int](repeating: 0, count: 30)
        dp[1] = 1
        dp[2] = 2
        dp[3] = 4
        if n <= 3 {
            print(dp[n])
            continue
        }
        for i in 4...n {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        }
        print(dp[n])
    }
}

input()
solution()

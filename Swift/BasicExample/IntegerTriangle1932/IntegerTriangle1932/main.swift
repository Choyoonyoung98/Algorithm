//
//  main.swift
//  IntegerTriangle1932
//
//  Created by 조윤영 on 2021/01/24.
//

import Foundation

var N: Int = 0
var dp = [[Int]]()
func input() {
    N = Int(String(readLine()!))!
    
    (0..<N).forEach { i in
        let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        dp.append(inputList)
        if i != 0 {
            (0..<inputList.count).forEach { j in
                if j == 0 {
                    dp[i][j] += dp[i-1][j]
                } else if j == inputList.count - 1 {
                    dp[i][j] += dp[i-1][j-1]
                } else {
                    dp[i][j] += max(dp[i-1][j-1], dp[i-1][j])
                }
            }
        }
    }
    
    var answer: Int = 0
    (0..<N).forEach{ i in
        answer = max(answer, dp[N-1][i])
    }
    
    print(answer)
}
func solution() {
    
}

input()
solution()

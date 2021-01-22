//
//  main.swift
//  Coin2293
//
//  Created by 조윤영 on 2021/01/22.
//

import Foundation

var N: Int = 0
var K: Int = 0
var coins = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    K = inputList[1]
    
    (0..<N).forEach{ _ in
        let c = Int(readLine()!)!
        coins.append(c)
    }
}

func solution() {
    var dp = [Int](repeating: 0, count: 10001)
    dp[0] = 1
    //1 2 5
    coins.sort()
    for coin in coins {
        if coin > K { break }
        for j in coin...K {
            dp[j] += dp[j - coin]
            if dp[j] > Int(pow(2.0, 31.0)){ dp[j] = 0 } //(*)
        }
    }
    
    print(dp[K])
}
input()
solution()

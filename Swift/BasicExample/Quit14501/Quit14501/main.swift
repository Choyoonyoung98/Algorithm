//
//  main.swift
//  Quit14501
//
//  Created by 조윤영 on 2021/01/24.
//

import Foundation

var N: Int = 0
var counseling = [(time: Int, price: Int)]()
var dp = [Int]()
func input() {
    N = Int(String(readLine()!))!
    dp = [Int](repeating: 0, count: N*2)
    (0..<N).forEach { i in
        let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let T = inputList[0]
        let P = inputList[1]
        counseling.append((time: T, price: P))
    }
}

func solution() {
    for i in 0..<N {
        let time = counseling[i].time
        let price = counseling[i].price
        //해당 날짜에 일을 맡을 경우
        if i + time <= N { dp[i+time] = max(dp[i+time], dp[i] + price) }
        //일을 맡지 않을 경우
        if i + 1 <= N { dp[i+1] = max(dp[i+1], dp[i])}
    }

    print(dp[N])
}

input()
solution()


//
//  main.swift
//  SoldierPlacement18353
//
//  Created by 조윤영 on 2021/01/25.
//
//LIS(Longest Increasing Subsequence): 최장 증가 부분 수열
//1. 동적 계획법 O(n^2)
//2. 이분탐색 lower_bound 사용 O(nlogn)
import Foundation

//최장감소부분수열
var N: Int = 0
var soldiers = [Int]()
var dp = [Int]()
func input() {
    N = Int(readLine()!)!
    dp = [Int](repeating: 0, count: N+1)
    soldiers = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
}

//dp풀이
func solution() {
    var answer = Int.max
    for i in 1..<N {
        for j in 0..<i {
            if soldiers[j] > soldiers[i] { dp[i] = max(dp[i], dp[j] + 1)}
            answer = min(answer, N - dp[i] - 1)
        }
    }
    if answer == N { print(0) }
    else { print(answer) }
}

//c++로 LIS 이분탐색으로도 풀어보기!!

input()
solution()

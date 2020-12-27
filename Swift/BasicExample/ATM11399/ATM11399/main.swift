//
//  main.swift
//  ATM11399
//
//  Created by 조윤영 on 2020/12/27.
//

import Foundation

var N: Int = 0
var times: [Int] = []

public func input() {
    let N = Int(readLine()!)
    times = readLine()!.split(separator: " ").map { Int($0)! }
}

public func  solution() -> Int {
    times.sort()
    var result: Int = 0
    var answer: Int = 0
    for t in times {
        result += t
        answer += result
    }
    return answer
}

input()
print(solution())

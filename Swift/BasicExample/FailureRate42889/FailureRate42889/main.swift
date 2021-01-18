//
//  main.swift
//  FailureRate42889
//
//  Created by 조윤영 on 2021/01/17.
//

import Foundation
var failures = [(index: Int, failure: Double)]()
func compare(a: (index: Int, failure: Double), b: (index: Int, failure: Double)) -> Bool {
    if a.failure >= b.failure { return a < b}
    else { return a > b}
}

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var answer = [Int]()
    var arrive_list = [Int](repeating: 0, count: N + 2)
    
    for s in stages { arrive_list[s] += 1 }
    
    var sum: Int = arrive_list[N+1]
    for i in (1 ... N).reversed() {
        sum += arrive_list[i]
        guard arrive_list[i] != 0 else {
            failures.append((index: i, failure: 0.0))
            continue
        }
        let failure = Double(arrive_list[i]) / Double(sum)
        failures.append((index: i, failure: failure))
    }
    answer = failures.sorted{ compare(a: $0, b: $1)}.map{ $0.index }
    return answer
}

let N: Int = 5
let stages: [Int] = [2, 1, 2, 6, 2, 4, 3, 3]
solution(N, stages)


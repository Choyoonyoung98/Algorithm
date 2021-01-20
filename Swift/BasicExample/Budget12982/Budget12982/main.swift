//
//  main.swift
//  Budget12982
//
//  Created by 조윤영 on 2021/01/20.
//

import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var answer = 0
    let d = d.sorted()
    var low = 0
    var high = d.count - 1
    
    if budget >= d.reduce(0){ $0 + $1 } { return d.count }
    while low <= high {
        var result = 0
        let mid = (low + high) / 2
        for i in 0..<mid { result += d[i] }
        
        if result <= budget {
            low = mid + 1
            answer = mid
        }
        else { high = mid - 1}
    }
    return answer
}

let d = [1,3,2,5,4]
let budget = 9
solution(d, budget)

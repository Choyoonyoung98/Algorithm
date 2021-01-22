//
//  main.swift
//  SteppingSone43236
//
//  Created by 조윤영 on 2021/01/19.
//

import Foundation

func solution(_ distance:Int, _ rocks:[Int], _ n:Int) -> Int {
    var answer = 0
    let rocks = rocks.sorted()
    
    var low = 1
    var high = distance
    
    while low <= high {
        var mid = (low + high) / 2
        var cnt = 0
        var prev = 0
        for i in 0..<rocks.count {
            if rocks[i] - prev < mid { cnt += 1}
            else { prev = rocks[i]}
        }
        
        if distance - prev < mid { cnt += 1 }
        if cnt > n { high = mid - 1}
        else {
            low = mid + 1
            answer = max(answer, mid)
        }
    }
    return answer
}

let distance = 25
let rocks =     [2, 14, 11, 21, 17]
let n = 2
solution(distance, rocks, n)

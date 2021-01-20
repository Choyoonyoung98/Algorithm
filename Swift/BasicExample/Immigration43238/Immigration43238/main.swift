//
//  main.swift
//  Immigration43238
//
//  Created by 조윤영 on 2021/01/20.
//

import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var answer: Int64 = 0
    
    let times = times.sorted()
    var low = 0
    var high = times[times.count - 1] * n
    //모두가 심사시간이 가장 오래 걸리는 심사관에게 검사를 맡을 경우
    while  low <= high {
        var sum = 0
        let mid = (low + high) / 2
        for t in times { sum += mid / t } //한 심사관 당 담당 수
        if n > sum { low = mid + 1 }
        else {
            high = mid - 1
            answer = Int64(mid)
        }
    }
    return answer
}

let n = 6
let times = [7, 10]
solution(n, times)

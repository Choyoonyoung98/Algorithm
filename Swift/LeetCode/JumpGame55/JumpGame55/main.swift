//
//  main.swift
//  JumpGame55
//
//  Created by 조윤영 on 2021/03/05.
//

import Foundation

//O(N^2)
func solution1(_ nums: [Int] ) -> Bool {
    if nums.count == 1 { return true }
    
    var reach = [Bool](repeating: false, count: nums.count+1)
    reach[0] = true;
    
    for (i, n) in nums.enumerated() {
        if !reach[i] { continue }
        //라고 구현했지만, 도달할 수 없는 i가 나오면 더이상 나아갈 수 없는 것과 마찬가지 이기 때문에 break가 더 맞는 것처럼 보인다
        if n == 0 { continue }
        for j in 1...n {
            let nextIndex = i + j
            if nextIndex == nums.count - 1 { return true }
            reach[nextIndex] = true
        }
    }
    return false
}

//O(N)
//reach bool 배열 -> 최대 도달할 수 있는 거리 프로퍼티 reachDistance
//뛸 수 있는 점프의 완전탐색 -> 최대 점프를 뛰었을 때의 결과 확인 후 reachdistance 업데이트
func solution2(_ nums: [Int] ) -> Bool {
    var reachDistance = 0
    
    for (i, n) in nums.enumerated() {
        if reachDistance < i { return false }
        let jumpCnt = n
        if i + jumpCnt >= nums.count - 1 { return true }
        reachDistance = max(reachDistance, i + jumpCnt)
    }
    return false
}

let nums = [2, 3, 1, 1, 4]
print(solution1(nums))

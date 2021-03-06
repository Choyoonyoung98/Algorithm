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
func solution2(_ nums: [Int] ) -> Bool {
    var reachDistance = 0
    
    //for i in 0..<reachDistance(x)
    for (i, n) in nums.enumerated() {
        if reachDistance < i { return false }
        let jumpCnt = n
        if i+jumpCnt >= nums.count - 1 { return true }
        reachDistance = max(reachDistance, i+jumpCnt)
    }
    return false
}

let nums = [2, 3, 1, 1, 4]
print(solution1(nums))

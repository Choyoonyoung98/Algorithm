//
//  main.swift
//  LuckyStraight18406
//
//  Created by 조윤영 on 2020/12/29.
//

import Foundation

var N: Int = 0
func input() {
    if let inputN = Int(readLine()!) {
        N = inputN
    }
}

func solution(_ N: Int) -> String {
    let n = String(N)
    
    //1234
    var left: Int = 0
    var right: Int = 0
    for i in 0..<n.count / 2 {
        if let leftN = Int(String(n[n.index(n.startIndex, offsetBy:i)])) {
            left += leftN
        }
        if let rightN = Int(String(n[n.index(n.startIndex, offsetBy: n.count/2 + i)])) {
            right += rightN
        }
    }
    
    //2
//    for (i, c) in n.enumerated() {
//        if i < n.count / 2 {
//            left += Int(String(c))!
//        } else {
//            right += Int(String(c))!
//        }
//    }
    
    if left == right { return "LUCKY"}
    else { return "READY" }
}

input()
print(solution(N))

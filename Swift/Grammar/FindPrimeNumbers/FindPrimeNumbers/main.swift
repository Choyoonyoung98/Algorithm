//
//  main.swift
//  FimdPrimeNumbers
//
//  Created by 조윤영 on 2021/02/05.
//

import Foundation
let MAX_SIZE = 501
func solution(_ N: Int) {
    var check = [Bool](repeating: true, count: MAX_SIZE)
    for i in 2...Int(sqrt(Double(N))) {
        if !check[i] { continue }
        for j in stride(from: i*i, through: N, by: i) {
            check[j] = false
        }
    }
    
    for i in 2...N {
        if check[i] { print(i, terminator:" ") }
    }
}

solution(20)


//
//  main.swift
//  Decomposition2231
//
//  Created by 조윤영 on 2021/02/08.
//

import Foundation

var N: String = ""
func input() {
    N = String(readLine()!)
}

func divideSum(_ n: Int) -> Int {
    return String(n).reduce(n) { $0 + Int(String($1))! } //(*)
}

func solution() -> Int {
    var answer = 0
    
    //216 각각의 자릿수가 가질 수 있는 최대값은 9이다.
    //따라서 216이 분해합이 될 수 있는 최소값은 216 - 3*9이다.
    let start = max(Int(N)! - (9*N.count), 1)
    for n in start ..< Int(N)! {
        if divideSum(n) == Int(N)! {
            answer = n
            break
        }
    }
    return answer
}
input()
print(solution())


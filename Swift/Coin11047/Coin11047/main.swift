//
//  main.swift
//  Coin11047
//
//  Created by 조윤영 on 2020/12/27.
//

import Foundation

var N: Int = 0
var K: Int = 0
var inputList: [Int] = []
var values: [Int] = []
public func input() {
    inputList = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    K = inputList[1]
    
    for _ in 0..<N {
        if let value: Int = Int(readLine()!) {
            values.append(value)
        }
    }
}

public func solution() -> Int {
    var answer: Int = 0
    var i: Int = 0
    //내림차순 정렬
    values.sort(by: >)
    
    while (K > 0 && i < N) {
        if( values[i] > K) { i += 1 }
        else {
            K -= values[i]
            answer += 1
        }
    }
    
    return answer
}

input()
print(solution())

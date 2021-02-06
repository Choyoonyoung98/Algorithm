//
//  main.swift
//  SubTotal1806
//
//  Created by 조윤영 on 2021/02/06.
//

import Foundation
let MAX_SIZE = 100001
var N: Int = 0
var S: Int = 0
var numbers = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    S = inputList[1]
    numbers = readLine()!.split(separator: " ").map{ Int(String($0))! }
}

func solution() -> Int {
    var answer = MAX_SIZE
    var i = 0
    var j = 0
    var sum = 0
    while true {
        if sum >= S {
            sum -= numbers[i]
            i += 1
        } else if j >= N { break }
        else {
            sum += numbers[j]
            j += 1
        }
        
        if sum >= S {
            answer = min(answer, j - i) }
    }
    
    if answer == MAX_SIZE { return 0 }
    return answer
}

input()
print(solution())

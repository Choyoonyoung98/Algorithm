//
//  main.swift
//  PickNumber2230
//
//  Created by 조윤영 on 2021/02/06.
//

import Foundation

var N: Int = 0
var M: Int = 0
var numbers = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]
    
    (0..<N).forEach{ _ in
        let x = Int(String(readLine()!))!
        numbers.append(x)
    }
}

func solution() -> Int {
    var answer = 2000000001;
    var i = 0
    var j = 0
    numbers.sort()
    
    //같은 투포인터 방법을 사용한다 하더라도 i와 j가 범위밖을 벗어날 우력가 있는지에 대해 잘 판단 해야 한다.
    while i < N && j < N {
        if numbers[j] - numbers[i] >= M {
            if answer == M { return M }
            answer = min(answer, numbers[j] - numbers[i])
            i += 1
        }
        else { j += 1 }
    }
    return answer
}

input()
print(solution())

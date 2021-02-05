//
//  main.swift
//  SequenceSumOfPrimeNumbers1644
//
//  Created by 조윤영 on 2021/02/04.
//

import Foundation

var N: Int = 0
func input() {
    N  = Int(String(readLine()!))!
}

func solution() -> Int{
    var answer: Int = 0
    if N == 1 { return 0 }
    //소수 리스트 뽑고-> 에라스토네스의 체
    var check = [Bool](repeating: true, count: N+1)
    
    //2. 2부터 시작해서 특정 수의 배수 지우기
    for i in 2...N { //(*) sqrt 하기 위한 방법
        if !check[i] { continue }
        for j in stride(from: i*i, through: N, by: i) {
            check[j] = false
        }
    }
    
    var candidate = [Int]()
    (2...N).forEach{ i in
        if check[i] { candidate.append(i) }
    }
    
    //투포인터 이용해서 답 찾기
    var i = 0
    var j = 0
    var sum = 0
    while true {
        if sum >= N {
            sum -= candidate[i]
            i += 1
        } else if j >= candidate.count { break }
        else if sum < N {
            sum += candidate[j]
            j += 1
        }
        if sum == N { answer += 1}
    }
    
    return answer
}


input()
print(solution())

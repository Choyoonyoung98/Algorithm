//
//  main.swift
//  ExactRanking38
//
//  Created by 조윤영 on 2021/01/26.
//

import Foundation

//Dijkstra
//pq 써야한다, 그런데 swift pq는 Comparable을 준수하기 때문에 한 번에 여러 개를 쌍으로 넣을 수 없다
//그런데 서칭해보니까 두 개의 쌍을 비교할 수 있는 방법을 발견해따 희희
//와 근데 Dijkstra가 아니라 플로이드와샬로 푸는데? ㅋㅎㅋㅎ
//결국 플로이드와샬로 풀었따

var N: Int = 0
var M: Int = 0
let INF = 501
var score_priority = [[Int]]()
public func input()  {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]

    score_priority = [[Int]](repeating: [Int](repeating: INF, count: N+1), count: N+1)
    (0..<M).forEach{ _ in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        
        let A = inputList2[0]
        let B = inputList2[1]
        score_priority[A][B] = 1
    }
}
public func solution() -> Int {
    var answer = 0
    for k in 1...N {
        for i in 1...N {
            for j in 1...N {
                score_priority[i][j] = min(score_priority[i][j], score_priority[i][k] + score_priority[k][j])
            }
        }
    }
    
    for i in 1...N {
        var cnt = 0
        for j in 1...N {
            if i == j || score_priority[i][j] != INF || score_priority[j][i] != INF { cnt += 1 }
        }
        if cnt == N { answer += 1 }
    }
    return answer
}

input()
print(solution())

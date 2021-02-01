//
//  main.swift
//  FinalRanking3665
//
//  Created by 조윤영 on 2021/02/01.
//

import Foundation

let MAX_SIZE = 501
var T: Int = 0
var N: Int = 0
var M: Int = 0
var inDegree = [Int]()
var graph = [[Bool]]()
var last_ranking = [Int]()
func input() {
    T = Int(String(readLine()!))!
    (0..<T).forEach{ _ in
        N = Int(String(readLine()!))!
        inDegree = [Int](repeating: 0, count: N+1)

        graph = [[Bool]](repeating: [Bool](repeating: false, count: N+1), count: N+1)
        last_ranking = [Int](repeating: 0, count: 1)
        last_ranking.append(contentsOf: readLine()!.split(separator: " ").map{ Int(String($0))! })
        
        (1...N-1).forEach{ i in
            let higherRankTeam = last_ranking[i]
            (i+1...N).forEach{ j in
                let lowerRankTeam = last_ranking[j]
                graph[higherRankTeam][lowerRankTeam] = true
                inDegree[lowerRankTeam] += 1
            }
        }
        M = Int(String(readLine()!))!
        (0..<M).forEach{ _ in
            let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
            let a = inputList[0]
            let b = inputList[1]
            if graph[a][b] {
                inDegree[a] += 1
                inDegree[b] -= 1
            } else {
                inDegree[b] += 1
                inDegree[a] -= 1
            }
            graph[a][b] = !graph[a][b]
            graph[b][a] = !graph[b][a]
        }
        print(solution())
    }
}

func solution() -> String {
    var answer = [String]()
    var cnt = 0
    var q = Queue<Int>()
    (1...N).forEach{ i in
        if inDegree[i] == 0 {
            cnt += 1
            inDegree[i] = MAX_SIZE
            q.push(i)
        }
    }
    if q.count > 1 { return "?" }
    while !q.empty() {
        let index = q.front()!
        q.pop()
        answer.append(String(index))
        (1...N).forEach{ i in
            if graph[index][i] == true {
                inDegree[i] -= 1
            }
        }
        
        (1...N).forEach{ i in if inDegree[i] == 0 {
            cnt += 1
            inDegree[i] = MAX_SIZE
            q.push(i)}
        }
        if q.count > 1 { return "?" }
    }
    
    if cnt != N { return "IMPOSSIBLE" }
    else {
        let result = answer.joined(separator: " ")
        return result
    }
}

input()

public struct Queue<T> {
    internal var data = Array<T>()
    public init() { }
    public var count: Int { return data.count }
    public func empty() -> Bool { return data.isEmpty }
    public func front() -> T? { return data.first }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeFirst() }
}


/*
3
5
5 4 3 2 1
2
2 4
3 4
3
2 3 1
0
4
1 2 3 4
3
1 2
3 4
2 3
 */

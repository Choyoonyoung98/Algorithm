//
//  main.swift
//  FindCity_18352
//
//  Created by 조윤영 on 2021/01/12.
//
//for문보다 forEach가 더 빠르다
import Foundation

var graph = [[Int]]()
var visited = [Bool]()
var dist_list = [Int]()
var N: Int = 0
var M: Int = 0
var K: Int = 0
var X: Int = 0
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    M = inputList[1]
    K = inputList[2]
    X = inputList[3]

    graph = [[Int]](repeating: [], count: N+1)
    visited = [Bool](repeating: false, count: N+1)
    dist_list = [Int](repeating: -1, count: N+1)
    
    (0..<M).forEach { _ in
        let roadInput = String(readLine()!).split(separator: " ").map{Int(String($0))!}
        let A: Int = roadInput[0]
        let B: Int = roadInput[1]
        graph[A].append(B)
    }
    solution()
}


func solution() {
    var q = Queue<(index: Int, dist: Int)>()
    q.push((index: X, dist: 0))
    dist_list[X] = 0
    while !q.isEmpty() {
        let index = q.front.index
        let dist = q.front.dist

        q.pop()
        if visited[index] { continue }
        visited[index] = true

        if dist > K { break }

        graph[index].forEach { nextIndex in
            if !visited[nextIndex] && dist_list[nextIndex] == -1 {
                dist_list[nextIndex] = dist + 1
                q.push((index: nextIndex, dist: dist+1))
            }
        }
    }
    let answer = dist_list.indices.filter{ dist_list[$0] == K }
    if answer.count == 0 { print(-1) }
    else {
        answer.forEach{ print($0) }
    }
}

public struct Queue<T> {
    internal var data = Array<T>()
    public init() { }
    
    public var front: T { return data.first! }
    public func isEmpty() -> Bool {
        return data.isEmpty
    }
    public var size: Int { return data.count }
    
    public mutating func push(_ element: T) {
        data.append(element)
    }
    
    public mutating func pop() {
        data.removeFirst()
    }
}

input()

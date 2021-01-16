//
//  main.swift
//  PopulationMovement16234
//
//  Created by 조윤영 on 2021/01/15.
//
//오른쪽 아래
import Foundation
var N: Int = 0
var L: Int = 0
var R: Int = 0
var map = [[Int]]()
let moveDir: [(y: Int, x: Int)] = [(1,0), (-1,0), (0,1), (0,-1)] //아래랑 우측만 검사
var visited = [[Bool]]()
var union = Queue<(y: Int, x: Int)>()
func input() {
    let inputList1: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList1[0]
    L = inputList1[1]
    R = inputList1[2]
    visited = [[Bool]](repeating: [Bool](repeating: false, count: N+1), count: N+1)
    (0..<N).forEach{ i in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
        map.append(inputList2)
    }
}

func isAvailable(_ y: Int, _ x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < N { return true }
    return false
}

func checkCanMove(from y1: Int, x1: Int, to y2: Int, x2: Int) -> Bool {
    if L <= abs(map[y1][x1] - map[y2][x2]) && abs(map[y1][x1] - map[y2][x2]) <= R { return true }
    return false
}

var cnt: Int = 0
var sum: Int = 0
var isMoving = false
func searchUnionCountry(_ startY: Int, startX: Int) {
    var q = Queue<(y: Int, x: Int)>()
    q.push((y: startY, x: startX))
    visited[startY][startX] = true
    cnt = 0
    sum = 0
    while !q.empty() {
        let y = q.front()!.y
        let x = q.front()!.x
        q.pop()
        union.push((y, x))
        cnt += 1
        sum += map[y][x]
        (0..<4).forEach { d in
            let nextY = y + moveDir[d].y
            let nextX = x + moveDir[d].x
            if isAvailable(nextY, nextX) && !visited[nextY][nextX] {
                if checkCanMove(from: y, x1: x, to: nextY, x2: nextX) {
                    visited[nextY][nextX] = true
                    q.push((nextY, nextX)) }
            }
        }
    }
    if union.size != 1 {
        isMoving = true
        moveBetweenUnion()
    }
    else { union.pop() }
}

func moveBetweenUnion() {
    let population = sum / cnt
    
    while !union.empty() {
        let y = union.front()!.y
        let x = union.front()!.x
        union.pop()
        map[y][x] = population
    }
}

func solution() -> Int {
    var answer: Int = 0
    while true {
        isMoving = false
        (0..<N).forEach { i in
            (0..<N).forEach{ j in
                if !visited[i][j] { searchUnionCountry(i, startX: j) }
            }
        }
        visited = [[Bool]](repeating: [Bool](repeating: false, count: N+1), count: N+1)
        if !isMoving { return answer }
        
        
        else { answer += 1 }
    }
}

input()
print(solution())

public struct Queue<T> {
    internal var data = Array<T>()
    public init() { }
    
    public func front() -> T? { return data.first }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeFirst() }
    public var size: Int { return data.count }
    public func empty() -> Bool { return data.isEmpty }
}

//
//  main.swift
//  Labatory14502
//
//  Created by 조윤영 on 2021/01/13.
//

import Foundation

var map = [[Int]]()
var N: Int = 0
var M: Int = 0
var viruses = Queue<(y: Int, x: Int)>()
let moveDir: [(y: Int, x: Int)] = [(y: 1, x: 0), (y: -1, x: 0), (y: 0, x: 1), (y: 0, x: -1)]
var zeroCnt = 0
var answer = -1
func input() {
    let inputList1: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList1[0]
    M = inputList1[1]
    
    (0..<N).forEach {i in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
        (0..<M).forEach{ j in
            if inputList2[j] == 2 { viruses.push((y: i, x: j))}
            else if inputList2[j] == 0 { zeroCnt += 1}
        }
        map.append(inputList2)
    }
    
    zeroCnt -= 3
}

var selected = [[Bool]]()
func setWall(_ y: Int, _ x: Int, cnt: Int) {
    if cnt == 3 {
        spreadVirus()
        return
    }
    var startY = y
    var startX = x
    if startX == M {
        startY += 1
        startX = 0
    }

    (startY..<N).forEach{ i in
        (startX..<M).forEach { j in
            if map[i][j] == 0 {
                map[i][j] = 1
                setWall(i, j+1, cnt: cnt+1)
                map[i][j] = 0
            }
            startX = 0
        }
    }
}
var copy_map = [[Int]]()
var copy_viruses = Queue<(y: Int, x: Int)>()
func isAvailable(_ y: Int, _ x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < M && copy_map[y][x] == 0 { return true }
    return false
}

func spreadVirus() {
    copy_map = map
    copy_viruses = viruses
    var currentZeroCnt = zeroCnt
    while(!copy_viruses.empty()) {
        let virusY = copy_viruses.front()!.y
        let virusX = copy_viruses.front()!.x
        copy_viruses.pop()
        (0..<4).forEach{ i in
            let nextVirusY = virusY + moveDir[i].y
            let nextVirusX = virusX + moveDir[i].x
            if isAvailable(nextVirusY, nextVirusX) {
                copy_map[nextVirusY][nextVirusX] = 2
                copy_viruses.push((nextVirusY, nextVirusX))
                currentZeroCnt -= 1
            }
        }
    }
    answer = max(answer, currentZeroCnt)
}

func solution() {
    copy_viruses = viruses
    copy_map = map
    setWall(0, 0, cnt: 0)
    print(answer)
}

input()
solution()

public struct Queue<T> {
    internal var data = Array<T>()
    public init() {}
    public var size: Int { return data.count }
    public func empty() -> Bool {
        return data.isEmpty
    }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeFirst() }
    public func front() -> T? { data.first }
}

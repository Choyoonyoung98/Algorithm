//
//  main.swift
//  CompetitiveTransmission18405
//
//  Created by 조윤영 on 2021/01/14.
//

import Foundation

var moveDir: [(y: Int, x: Int)] = [(y: -1, x: 0), (y: 1, x: 0), (y: 0, x: -1), (y: 0, x: 1)]
var map = [[Int]]()
var N: Int = 0
var K: Int = 0
var S: Int = 0
var X: Int = 0
var Y: Int = 0
var virus = [Object]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    N = inputList[0]
    K = inputList[1]
    (0..<N).forEach{ i in
        let inputList2: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
        (0..<N).forEach{ j in if inputList2[j] != 0 { virus.append(Object(index: inputList2[j], y: i, x: j)) }}
        map.append(inputList2)
    }
    
    let inputList3: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
    S = inputList3[0]
    X = inputList3[1]
    Y = inputList3[2]
}

func isAvailable(_ y: Int, _ x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < N && map[y][x] == 0 { return true }
    return false
}

func solution() -> Int {
    var time = 0
    virus.sort()
    while virus.count != 0 {
        time += 1
        var spreadVirus = [Object]()
        for i in 0..<virus.count {
            let index = virus.first!.index
            let y = virus.first!.y
            let x = virus.first!.x

            virus.removeFirst()
            if time == S+1 { return map[X-1][Y-1] }
            
            (0..<4).forEach { d in
                let nextY = y + moveDir[d].y
                let nextX = x + moveDir[d].x
                if isAvailable(nextY, nextX) {
                    map[nextY][nextX] = index
                    spreadVirus.append(Object(index: map[nextY][nextX], y: nextY, x: nextX))
                }
            }
        }
        virus.append(contentsOf: spreadVirus)
    }
    
    return map[X-1][Y-1]
}

input()
print(solution())

//낮은 종류의 바이러스부터 먼저 증식
struct Object: Comparable {
    let index: Int
    let y: Int
    let x: Int
    static func < (first: Object, second: Object) -> Bool { return first.index < second.index }
}

//
//  main.swift
//  AvoidSurveillance18428
//
//  Created by 조윤영 on 2021/01/15.
//

import Foundation

var N: Int = 0
var map = [[String]]()
var students = [(y: Int, x: Int)]()
var teachers = [(y: Int, x: Int)]()
let moveDir: [(y: Int, x: Int)] = [(-1,0),(1,0),(0,-1),(0,1)]
func input() {
    if let n = readLine() {
        N = Int(n)!
    }
    
    (0..<N).forEach{ i in
        let inputList: [String] = readLine()!.split(separator: " ").map{ String($0) }
        (0..<N).forEach{ j in
            if inputList[j] == "T" { teachers.append((i, j))}
        }
        map.append(inputList)
    }
}

var findAnswer = false
func setWall(_ y: Int, _ x: Int, _ cnt: Int) {
    if cnt == 3 {
        if startSurveillance() {
            print("YES")
            findAnswer = true
        }
        return
    }
    
    var currentY = y
    var currentX = x + 1
    if currentX == N {
        currentY += 1
        currentX = 0
    }
    
    for i in currentY..<N {
        for j in currentX..<N {
            if map[i][j] == "X" {
                map[i][j] = "W"
                setWall(i, j, cnt+1)
                
                if findAnswer { return }
                map[i][j] = "X"
            }
            currentX = 0
        }
    }
}

func isAvailable(y: Int, x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < N { return true }
    return false
}

func startSurveillance() -> Bool {
    for i in 0..<teachers.count {
        let y = teachers[i].y
        let x = teachers[i].x
        for d in 0..<4 {
            var nextY = y + moveDir[d].y
            var nextX = x + moveDir[d].x
            while isAvailable(y: nextY, x: nextX) {
                if map[nextY][nextX] == "W" { break }
                if map[nextY][nextX] == "S" { return false }
                nextY += moveDir[d].y
                nextX += moveDir[d].x
            }
        }
    }
    
    return true
}

func solution() {
    setWall(0, 0, 0)
    if !findAnswer { print("NO") }
}
input()
solution()


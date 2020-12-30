//
//  main.swift
//  Snake3190
//
//  Created by 조윤영 on 2020/12/29.
//

import Foundation

var room = [[Int]]()
var N: Int = 0
var K: Int = 0
var L: Int = 0
var appleInfo = [(y: Int, x: Int)]()
var moveInfo = [(time: Int, dir: String)]()
var moveDir: [(y: Int, x: Int)] = [(-1, 0), (0, -1), (1, 0), (0, 1)] //상 좌 하 우

func input() {
    if let rL = readLine() {
        N = Int(rL)!
    }
    room = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)
    
    if let rL = readLine() {
        K = Int(rL)!
    }
    var temp = [String]()
    for _ in 0..<K {
        temp = readLine()!.split(separator: " ").map { String($0) }
        let y = Int(temp[0])!
        let x = Int(temp[1])!
        room[y - 1][x - 1] = 3 // 사과
    }
    
    if let rL = readLine() {
        L = Int(rL)!
    }
    for _ in 0..<L {
        temp = readLine()!.split(separator: " ").map{ String($0) }
        moveInfo.append((time: Int(temp[0])!, dir: temp[1]))
    }
}

func isAvailable(_ y: Int, _ x: Int) -> Bool {
    if 0 <= y && y < N && 0 <= x && x < N && room[y][x] != 1 { return true }
    else { return false }
}

func solution() -> Int{
    var rotationCnt = 0
    var time = 0
    var currentY = 0
    var currentX = 0
    var dir = 3 // 우
    room[0][0] = 1
    
    var q = Queue<(y: Int, x: Int)>()
    q.push(element: (0,0))
    
    while true {
        time += 1
        let nextY = currentY + moveDir[dir].y
        let nextX = currentX + moveDir[dir].x
        if isAvailable(nextY, nextX) {
        
            //사과가 없다면
            if room[nextY][nextX] != 3 {
                let prevY = q.top()!.y
                let prevX = q.top()!.x
                room[prevY][prevX] = 0
                q.pop()
            }
            room[nextY][nextX] = 1
            q.push(element: (nextY, nextX))
            currentY = nextY
            currentX = nextX
        } else { return time }
        //방향 전환의 시간이 되면
        if rotationCnt < moveInfo.count && time == moveInfo[rotationCnt].time {
            let rotation = moveInfo[rotationCnt].dir
            let nextDir = (rotation == "L") ?  (dir + 1) % 4 : (dir + 4 - 1) % 4
            dir = nextDir
            rotationCnt += 1
        }
    }
    
    return time
}

input()
print(solution())


public struct Queue<T> {
    public init() { }
    internal var data = Array<T>() //뒤에 ()로 선언하는 거 잊지말기
    
    func top() -> T? {
        return data.first
    }
    mutating func pop() {
        data.removeFirst()
    }
    
    mutating func push(element: T) {
        data.append(element)
    }
    
    func isEmpty() -> Bool{
        return data.isEmpty
    }
}

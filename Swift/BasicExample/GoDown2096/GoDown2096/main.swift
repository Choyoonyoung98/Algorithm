//
//  main.swift
//  GoDown2096
//
//  Created by 조윤영 on 2021/02/09.
//
//문제 똑바로 읽고 이해하기
//swift의 경우에는 굳이 큰 수를 배열에 미리 할당할 필요성이 있는지에 대해 꼭 되돌아보기!!!!!
import Foundation

var N: Int = 0
var board = [[Int]]()
func input() {
    N = Int(String(readLine()!))!
    (0..<N).forEach{ _ in
        let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        board.append(inputList)
    }
}

var maxAnswer = 0
var minAnswer = 900000
func findScore() {
    
    var maxCosts = board
    var minCosts = board
    
    if N != 1 {
        (1..<N).forEach{ y in
            (0..<3).forEach{ x in
                if x == 0 {
                    minCosts[y][0] += min(minCosts[y-1][0], minCosts[y-1][1])
                    maxCosts[y][0] += max(maxCosts[y-1][0], maxCosts[y-1][1])
                } else if x == 2 {
                    minCosts[y][x] += min(minCosts[y-1][1], minCosts[y-1][2])
                    maxCosts[y][x] += max(maxCosts[y-1][1], maxCosts[y-1][2])
                } else { // x == 1
                    minCosts[y][1] += min(minCosts[y-1][0], minCosts[y-1][1], minCosts[y-1][2])
                    maxCosts[y][1] += max(maxCosts[y-1][0], maxCosts[y-1][1], maxCosts[y-1][2])
                }
            }
        }
    }

    print(maxCosts.last!.max()!, minCosts.last!.min()!, separator: " ")
    
}

func solution() {
    findScore()
}

input()
solution()

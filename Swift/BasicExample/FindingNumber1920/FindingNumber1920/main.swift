//
//  main.swift
//  FindingNumber1920
//
//  Created by 조윤영 on 2021/01/18.
//
//이 문제의 목표는 이분탐색에 대한 이해이지만, 해쉬를 쓰면 더 빨리 문제를 해결할 수 있다
import Foundation

var N: Int = 0
var numb_list = [Int]()
var M: Int = 0
var input_list = [Int]()
func input() {
    if let n = readLine() {
        N = Int(n)!
    }
    numb_list = readLine()!.split(separator: " ").map{ Int($0)! }
    if let m = readLine() {
        M = Int(m)!
    }
    input_list = readLine()!.split(separator: " ").map{ Int($0)! }
}

func solution() {
    numb_list.sort()
    
    for x in input_list {
        var left = 0
        var right = N - 1
        var mid = (left + right) / 2
        var isExist = false
        while left <= right {
            mid = (left + right) / 2
            if numb_list[mid] > x { right = mid - 1}
            else if numb_list[mid] < x { left = mid + 1}
            else {
                print(1)
                isExist = true
                break
            }
        }
        if !isExist { print(0) }
    }
}

input()
solution()


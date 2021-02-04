//
//  main.swift
//  SumOfNumbers(2)2003
//
//  Created by 조윤영 on 2021/02/04.
//

import Foundation
var N: Int = 0
var M: Int = 0
var numbers = [Int]()
func input() {
    let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = inputList[0]
    M = inputList[1]
    
    numbers = readLine()!.split(separator: " ").map{ Int(String($0))! }
}

//1 2 3 4 2 5 3 1 1 2
//시간 복잡도: O(n)
func solution() -> Int {
    var answer = 0
    var i = 0
    var j = 0
    var sum = 0
    
    while true {
        if sum >= M {
            sum -= numbers[i]
            i += 1
        } else { //sum < M
            if j >= N { break }
            sum += numbers[j]
            j += 1
        }
        if sum == M { answer += 1 }
    }
    return answer
}

input()
print(solution());

public struct Queue<T> {
    internal var data = Array<T>()
    public init() { }
    public var count: Int { return data.count }
    public func front() -> T? { return data.first }
    public func isEmpty() -> Bool { return data.isEmpty }
    public mutating func push(_ element: T) { data.append(element) }
    public mutating func pop() { data.removeFirst() }
}

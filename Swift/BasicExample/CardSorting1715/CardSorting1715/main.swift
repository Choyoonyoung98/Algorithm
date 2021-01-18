//
//  main.swift
//  CardSorting1715
//
//  Created by 조윤영 on 2021/01/17.
//
/*
 카드 수를 정렬했을 때 10 20 40 이라면
 당장 이 순간에는 (10+20) + (30 + 40)이 최소 교환횟수가 된다
 그런데 다른 경우를 생각해보면 이전 카드의 합이 남은 카드의 묶음 수보다 커지는 경우가 있다
 예를 들어
 50 80 90 100 의 카드 묶음이 있다면
 (50+80)은 130의 비교횟수를 가지게 되는데 (130+90) + (210+100)의 경우보다
 (90+100) + (130+190)의 경우에 비교횟수를 더 적게 가지게 된다
 왜냐하면 카드를 합친 이후에는 카드 묶음의 정렬이 흐트러지게 되기 때문이다. 130 90 100이므로
 다시 정렬을 해야한다. 따라서 그때그때 우선이 되는 카드묶음을 찾기 위해 우선순위 큐가 필요하다.
 또한 매번 정렬은 그냥 하게 되면 시간적인 낭비가 심하게 되므로 최소힙 알고리즘을 포함하는 우선순위 큐의 방법이 적절하다
 */

import Foundation

var N: Int = 0
var card_list = PriorityQueue<Int>()
func input() {
    N = Int(readLine()!)!
    (0..<N).forEach{ _ in
        let card = Int(readLine()!)!
        card_list.push(card)
    }
}

func solution() -> Int {
    var answer: Int = 0
    while card_list.count != 1 {
        
        let card1: Int = card_list.top()!
        card_list.pop()
        let card2: Int = card_list.top()!
        card_list.pop()
        answer += (card1 + card2)
        card_list.push(card1 + card2)
    }
    return answer
}

input()
print(solution())


public struct PriorityQueue<T: Comparable> {
    internal var heap = Array<T>()
    public let ordered: (T, T) -> Bool
    public init(isUpper: Bool = true) {
        if isUpper { ordered = { $0 > $1} }
        else { ordered = {$0 < $1} }
    }
    
    public var count: Int { return heap.count }
    public func top() -> T? { return heap.first }
    public func empty() -> Bool { return heap.isEmpty }
    public mutating func push(_ element: T) {
        heap.append(element)
        swim(heap.count - 1)
    }
    public mutating func pop() {
            guard heap.count != 1 else {
                heap.removeLast()
                return
            }
            heap.swapAt(0, heap.count - 1)
            heap.removeLast()
            sink(0)
    }
    
    public mutating func sink(_ index: Int) { //힙의 재구성
        var index = index
        
        while 2 * index + 1 < heap.count {
            var j = 2 * index + 1 //왼쪽 자식 노드
            if j + 1 < heap.count && ordered(heap[j], heap[j+1]) { j += 1}
            if !ordered(heap[index], heap[j]) { break }
            heap.swapAt(index, j)
            index = j
        }
    }
    
    public mutating func swim(_ index: Int) { //힙의 구성
        var index = index
        
        while index > 0 && ordered(heap[(index - 1) / 2], heap[index]) {
            heap.swapAt((index - 1) / 2, index)
            index = (index - 1) / 2
        }
    }
}

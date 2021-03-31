//
//  main.swift
//  CoursesSchedule207
//
//  Created by 조윤영 on 2021/03/31.
//

import Foundation

/*위상정렬 알고리즘*/
func canFinish(_ numCourses: Int, _ prerequisites: [[Int]]) -> Bool {
    if prerequisites.count == 0 { return true } //우선순위가 없을 경우, 우선순위를 부정할 수 있는 경우의 수가 없기 때문에 즉시 ture 리턴
    
    var inDegree = [Int](repeating: 0, count: numCourses)
    var graph = [[Bool]](repeating: [Bool](repeating: false, count: numCourses), count: numCourses)
    var q = Queue<Int>()
    
    /*1: 그래프의 간선 정보 초기화*/
    for p in prerequisites {
        let a = p[0]
        let b = p[1]
        graph[b][a] = true //0번째 인덱스에는 우선으로 방문해야 하는 인덱스를, 1번째 인덱스에는 이후에 방문해야 하는 인덱스 정보를 담아준다
        inDegree[a] += 1 //진입차수 증가
    }
    
    /*2: 처음 시작할 때 진입차수가 0인 노드를 큐에 삽입해준다*/
    (0..<numCourses).forEach { i in
        if inDegree[i] == 0 { q.push(i) }
    }
    
    /*3: 위상정렬 시작*/
    for _ in 0..<numCourses {
        // if q.count >= 2  { return false } //not certain -> 꼭 한가지의 경우의 수만을 추출하지 않아도 되기 때문에 해당 조건은 사용하지 않습니다
        if q.count == 0 { return false } //cycle이 생길 경우 return false
        
        let idx = q.front()!
        q.pop()
        
        for (destIdx, isConnected) in graph[idx].enumerated() { //진입할 수 있는 다음 노드들에 대해서 탐색
            if !isConnected { continue }
            inDegree[destIdx] -= 1
            if inDegree[destIdx] == 0 { q.push(destIdx) }
        }
    }
    return true
}

let numCourses = 2
let prerequisities = [[1,0],[0,1]]
print(canFinish(numCourses, prerequisities))

//큐 구조체 구현
struct Queue<T> {
    var data = Array<T>()
    public init() { }
    
    var count: Int { return data.count }
    var isEmpty: Bool {return data.isEmpty }
    func front() -> T? { return data.first }
    mutating func push(_ element: T) { data.append(element) }
    mutating func pop() { data.removeFirst() }
}

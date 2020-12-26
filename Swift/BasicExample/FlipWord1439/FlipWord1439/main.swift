//
//  main.swift
//  FlipWord1439
//
//  Created by 조윤영 on 2020/12/26.
//

var word: String = "" //입력받을 변수에 대해서 초기화 필요

public func input() {
    word = readLine()!//옵셔널을 해제해주는 이유는 readLine은 표준 입력으로 받은 걸 읽어 String?을 리턴한다고 나타나 있다. 그래서 위와 같이 옵셔널을 해제해주는 작업이 필요하다
}

public func countFlip(_ n: Int) -> Int {
    var result: Int = 0
    var foundN: Bool = false
    
    for w in word {
        if w == String(n)[String(n).startIndex] {
            if !foundN {
                foundN = true
                result += 1
            }
        } else if foundN {
            foundN = false
        }
    }
    return result
}

public func solution() -> Int {
    let answer: Int = min(countFlip(1), countFlip(0))
    return answer
}

input()
print("\(solution())\n")

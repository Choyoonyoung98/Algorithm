//
//  main.swift
//  KoreanEnglishMath10825
//
//  Created by 조윤영 on 2020/12/31.
//

import Foundation

var N: Int = 0
var scoreLisit = [(name: String, korean: Int, english: Int, math: Int)]()

func input() {
    if let inputN = Int(readLine()!) { N = inputN }
    for _ in 0..<N {
        let inputList: [String] = readLine()!.split(separator: " ").map{ String($0) }
        let name = inputList[0]
        let korean = Int(inputList[1])!
        let english = Int(inputList[2])!
        let math = Int(inputList[3])!
        scoreLisit.append((name: name, korean: korean, english: english, math: math))
    }
}

func solution() {
    scoreLisit.sort {
        if $0.korean == $1.korean && $0.english == $1.english && $0.math == $1.math { return $0.name < $1.name }
        else if $0.korean == $1.korean && $0.english == $1.english { return $0.math > $1.math }
        else if $0.korean == $1.korean { return $0.english < $1.english }
        else { return $0.korean > $1.korean }
    }
    
    for score in scoreLisit { print(score.name) }
}

input()
solution()



//
//  main.swift
//  GroupWordChecker
//
//  Created by 조윤영 on 2021/01/02.
//

import Foundation

public func input() {
    var result: Int = 0
    if let N: Int = Int(readLine()!) {
        for _ in 0..<N {
            if let word: String = readLine() {
                if checkIsGroupWord(word) { result += 1 }
            }
        }
    }
    
    print(result)
}

public func checkIsGroupWord(_ word: String) -> Bool {
    var dict = Dictionary<Character, Int>()
    
    var prevW: Character = " "
    for w in word {
        if prevW != w && dict[w] != nil { return false }
        if prevW != w {
            dict.updateValue(0, forKey: w)
            prevW = w
        }
        dict[w]! += 1
    }
    
    return true
}

input()

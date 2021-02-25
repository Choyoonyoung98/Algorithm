//
//  main.swift
//  DecodeWays91
//
//  Created by 조윤영 on 2021/02/15.
//

import Foundation
//https://leetcode.com/problems/decode-ways/
//"111111111111111111111111111111111111111111111"부터 timeout
//let mapping: [String] = ["","A","B","C","D","E","F","G","H","I","J","K","L","M","N", "O","P","Q","R","S","T","U","V","W","X","Y","Z"]
//var answer: Int = 0
//func makeCombination(_ s: String, _ result: String, _ index: Int) {
//    if index == s.count {
//        answer += 1
//        print(result)
//        return
//    }
//
//    if s[s.index(s.startIndex, offsetBy:index)] == "0" { return }
//
//    for i in 1...2 {
//        if index + i > s.count { return }
//        let range = s.index(s.startIndex, offsetBy: index)..<s.index(s.startIndex, offsetBy: index + i)
//        let numb = Int(String(s[range]))!
//        if numb > 26 { return }
//        print("\(numb)->\(mapping[numb])")
//        let newResult = result + mapping[numb]
//        makeCombination(s, newResult, index+i)
//    }
//}

//
//func numDecodings(_ s: String) -> Int {
//    makeCombination(s, "", 0)
//    return answer
//}
//


func numDecodings(_ s: String) -> Int {
        var memo = [Int](repeating: 0, count: s.count+1)
        memo[s.count] = 1
        memo[s.count - 1] = s[s.index(before: s.endIndex)] != "0" ? 1: 0
        if s.count - 2 >= 0 {
            for i in (0...s.count - 2).reversed() {
                if s[s.index(s.startIndex, offsetBy: i)] == "0" { continue }
                else { memo[i] = Int(s[s.index(s.startIndex, offsetBy: i)...s.index(s.startIndex, offsetBy: i+1)])! <= 26 ? memo[i+1] + memo[i+2] : memo[i+1] }
            }
        }
        
        return memo[0]
    }

let str = "12345"
print(str[str.index(str.startIndex, offsetBy: 1)...str.index(after: str.index(str.startIndex, offsetBy: 1))])

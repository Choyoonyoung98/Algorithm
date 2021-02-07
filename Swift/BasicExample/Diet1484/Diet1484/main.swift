//
//  main.swift
//  Diet1484
//
//  Created by 조윤영 on 2021/02/06.
//

import Foundation

var G: Int = 0
func input() {
    G = Int(String(readLine()!))!
}

//투포인터 구현 시에는 구현 순서에 대해 신경써라
func solution() {
    var cnt = 0
    var i = 1
    var j = 1
    while i <= G && j <= G {
        if pow(j, 2) - pow(i, 2) == G {
            cnt += 1
            print(j)
        }
        if pow(j, 2) - pow(i, 2) >= G {
            i += 1
        } else {
            j += 1
        }
    }
    if cnt == 0 { print(-1) }
}

func pow(_ x: Int, _ n: Int) -> Int {
    if n == 0 { return 1 }
    return x * pow(x, n-1)
}

input()
solution()


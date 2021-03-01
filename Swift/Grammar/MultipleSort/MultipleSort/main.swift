//
//  main.swift
//  MultipleSort
//
//  Created by 조윤영 on 2021/02/01.
//

import Foundation

var test: [(cost: Int, y: Int, z: Int)]  = [(1,2,3),(3,2,1),(10,3,2),(15,18,3),(20,1,25)]
test.sort{
    if $0.cost > $1.cost { return $0 < $1 }
    else { return $0 > $1 }
}


print(test)

var costs: [(cost: Int, a: Int, b: Int)] = [(cost: 11, a: 3, b: 2), (cost: 10, a: 1, b: 0), (cost: 0, a: 1, b: 0), (cost: 1, a: 0, b: 3), (cost: 1, a: 3, b: 1), (cost: 10, a: 2, b: 1), (cost: 3, a: 1, b: 0), (cost: 0, a: 4, b: 3), (cost: 4, a: 3, b: 2), (cost: 5, a: 4, b: 1), (cost: 3, a: 2, b: 4), (cost: 20, a: 4, b: 3)]
costs.sort{
    return $0.cost < $1.cost
}

print(costs)

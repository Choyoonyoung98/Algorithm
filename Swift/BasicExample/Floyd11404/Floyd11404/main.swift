  //
//  main.swift
//  Floyd11404
//
//  Created by 조윤영 on 2021/01/25.
//
  //A->B까지 가는데 필요한 비용의 최소값: 다익스트라, 플로이드
  //다익스트라: 하나의 지점에서 여러 지점까지의 최소비용을 구하는 것에 적합
  //플로이드: 여러 지점에서 여러 지점까지의 최소비용을 구하는 것에 적합
  //그런데 해당 문제는 모든 도시쌍에 대하여 최소비용을 구해야 하므로 플로이드 알고리즘이 적합
  /*한 번 타는데 비용이 최대 100,000보다 작거나 같다고 했는데 MAX_SIZE를 1000,000로 지정해야 하는 이유*/
  //: 다른 버스 환승을 할 경우 100,000 비용보다 더 클 수 있기 때문이다
  import Foundation
  let MAX_SIZE: Int = 10000001 //최대값 주의!!!
  var N: Int = 0
  var M: Int = 0
  var dp = [[Int]]()
  func input() {
    N = Int(String(readLine()!))!
    M = Int(String(readLine()!))!
    dp = [[Int]](repeating: [Int](repeating: MAX_SIZE, count: N), count: N)
    (0..<M).forEach{ i in
        let inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

        let busA = inputList[0] - 1
        let busB = inputList[1] - 1
        let cost = inputList[2]
        dp[busA][busB] = min(dp[busA][busB], cost)
    }
  }
  
  func solution() {
    for k in 0..<N { //가장 바깥에 둬야한다
        for i in 0..<N {
            for j in 0..<N {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
            }
        }
    }
    
    for i in 0..<N {
        for j in 0..<N {
            print(dp[i][j] == MAX_SIZE || i == j  ? 0 : dp[i][j], terminator: " ")
        }
        print()
    }
  }

  input()
  solution()

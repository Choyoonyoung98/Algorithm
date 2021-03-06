//
//  main.swift
//  Mukbang42891
//
//  Created by 조윤영 on 2020/12/28.
//

import Foundation

func solution(_ food_times:[Int], _ k:Int64) -> Int {
    guard food_times.reduce(0, +) > k else { return -1 }
    var K: Int = Int(k)
    var food_info: [(time: Int, index: Int)] = food_times.enumerated().map{($1, $0)}.sorted(by: <)
    //pair의 형태로 데이터 타입을 저장할 수 있다
    //enumerated로 $0에 index를, $1에 해당 index의 배열값에 접근할 수 있다
    
    var i: Int = 0 //먹기를 완료한 음식의 수
    var j: Int = 0 //동일한 먹기 시간을 가진 음식의 수
    var cycle: Int = 0
    //3 1 2
    //3 2 2 -> 2 2 3
    while i < food_times.count && K >= (food_info.count - i) * (food_info[i].time - cycle) {
        j = i
        //다음으로 먹을 음식 중에 먹는 시간이 같은 음식이 있는지 확인
        // i...food_times.count - 1
        while j < food_info.count && food_info[i].time == food_info[j].time { j += 1}
            
        let extraCycle = food_info[i].time - cycle//음식 먹기를 완료하기까지 추가로 필요한 시간(회전 사이클 수)
        let extraEatingTime = (food_info.count - i ) * extraCycle //다 먹기까지 걸리는 시간
        K -= extraEatingTime

        cycle = food_info[i].time
        i = j
    }

    //정렬 기준을 명시해주는 이유는 index가 2번째 원소이기 때문.. 중요중요
    food_info = food_info[i...].sorted { $0.index < $1.index }
    
    return food_info[K % food_info.count].index + 1
}

let food_times: [Int] = [3, 1, 2]
let k: Int64 = 5
print(solution(food_times, k))


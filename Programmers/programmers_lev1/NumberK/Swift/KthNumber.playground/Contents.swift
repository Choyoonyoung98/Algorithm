import Foundation
let array:[Int] = [1, 5, 2, 6, 3, 7, 4]
let commands:[[Int]] = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
solution(array, commands)

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer = [Int]()
    for command in commands {
        let startNumb:Int = command[0] - 1
        let endNumb:Int = command[1] - 1
        let position:Int = command[2] - 1

        var temp_array = [Int]()
        for var i in startNumb...endNumb {
            temp_array.append(array[i])
            
        }
        temp_array = temp_array.sorted(by: {$0 < $1})
        answer.append(temp_array[position])
    }

    return answer
}

func solution2(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    return commands.map({(key) in
        return array[(key[0]-1)...(key[1]-1)].sorted()[key[2]-1]
    })
}

func solution3(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    return commands.map {
        let i = $0[0]-1;
        let j = $0[1]-1;
        let k = $0[2]-1
        return array[i...j].sorted()[k]
    }
}

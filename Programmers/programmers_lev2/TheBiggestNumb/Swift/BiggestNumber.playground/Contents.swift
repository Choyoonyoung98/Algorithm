import UIKit

let numbers:[Int] = [6, 10, 2]
let visited =  [Int]()
solution(numbers)

func solution(_ numbers:[Int]) -> String {
    
    let sortedNumbers = numbers.sorted {
        Int("\($0)\($1)")! > Int("\($1)\($0)")!
    }
    
    let answer = sortedNumbers.map {String($0)}.reduce("") { $0 + $1 }
    return sortedNumbers.first == 0 ? "0" : answer
}

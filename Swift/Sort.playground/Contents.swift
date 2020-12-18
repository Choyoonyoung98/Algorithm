import UIKit

var str = "Hello, playground"

//버블소트 구현
public func bubbleSort(_ array: [Int]) -> [Int] {
    var temp_array: [Int] = array
    for i in (1..<array.count - 1).reversed() {
        for j in 0...i {
            print("\(j): \(temp_array[j])")
            if temp_array[j+1] < temp_array[j] {
                let temp = temp_array[j+1]
                temp_array[j+1] = temp_array[j]
                temp_array[j] = temp
            }
        }
    }
    
    return temp_array
}

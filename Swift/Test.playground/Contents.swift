import UIKit
import Foundation

//팩토리얼 구현
public func factorial(_ n: Int) -> Int {
    if(n == 1) { return 1 }
    return n * factorial(n-1)
}

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

factorial(3)
let array: [Int] = [10, 9, 8, 7]
for a in bubbleSort(array) {
    print(a)
}

/*
 - 자연수를 입력받으면 3진수로 변환된 문자열을 반환하는 함수를 작성해주세요.
 - 0, 1 로 이루어진 문자열을 입력으로 받아 이를 10진수 정수로 출력하는 함수를 작성해주세요. 
     * let result = toDecimal(from: "0011")    // result : 3
 */

public func toDecimal(from number: String) -> String {
    var answer = 0

    var index: Int = 0
    for i in (0..<number.count).reversed() {
        let n = number[number.index(number.startIndex, offsetBy: i)]

        answer += Int(String(n))! * index * 3
        index += 1
    }
    
    return String(answer)
}

toDecimal(from: "0011")

/*
 - 자연수(N)를 입력받아 N의 각 자릿수의 합을 반환하는 함수를 작성해주세요.
     * N = 123이면, 결과는 1+2+3 = 6
 */

public func calculateSum(_ number: Int) -> Int{
    var answer: Int = 0
    let s_number = String(number)
    for n in s_number {
        answer += Int(String(n))!
    }
    
    return answer
}

print(calculateSum(123))


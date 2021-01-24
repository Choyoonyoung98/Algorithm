//
//  main.swift
//  SortAlgorithm
//
//  Created by 조윤영 on 2021/01/23.
//

import Foundation
let array: [Int] = [3,1,9,8,7,5]

/*<버블소트 구현>: 뒤부터 정렬해나간다*/
//최선: O(N) - 이미 정렬된 상태라면
//평균/최악: O(N^2)
public func bubbleSort(_ array: [Int]) -> [Int] {
    var array: [Int] = array
    if array.count == 1 { return array }
    for i in (0..<array.count).reversed() {
        for j in 0..<i {
            if array[j] > array[j+1] {
                let temp = array[j+1]
                array[j+1] = array[j]
                array[j] = temp
            }
        }
    }
    return array
}
print("[버블소트]: \(bubbleSort(array))")

/*선택소트 구현: 앞부터 정렬해나간다*/
//최선/최악/평균: O(N^2)
public func selectionSort(_ array: [Int]) -> [Int] {
    var array: [Int] = array
    
    for i in 0..<array.count - 1 {
        var index = i
        for j in i+1..<array.count {
            if array[index] > array[j] { index = j }
        }
        
        let temp = array[index]
        array[index] = array[i]
        array[i] = temp
    }
    return array
}

print("[선택소트]: \(selectionSort(array))")

/*삽입소트 구현: 앞부터 정렬해나간다*/
//최선: O(N)
//최악/평균: O(N^2)
public func insertSort(_ array: [Int]) -> [Int] {
    var array: [Int] = array
    if array.count == 1 { return array }
    for i in 1..<array.count {
        for j in (0..<i).reversed() {
            guard array[j] > array[j+1] else { break }
            let temp = array[j+1]
            array[j+1] = array[j]
            array[j] = temp
        }
    }
    return array
}

print("[삽입소트]: \(insertSort(array))")

/*퀵소트*/
//최선/평균: O(nlogn)
//최악: O(n^2)
var quickSortedArray = [Int]()
public func quickSortSolution() {
    quickSortedArray = array
    quickSort(0, array.count - 1)
    print("[퀵소트]: \(quickSortedArray)")
}
quickSortSolution()

public func quickSort(_ left: Int, _ right: Int) {
    if left >= right { return }
    var i = left + 1
    var j = right
    let pivot = left
    while i <= j {
        while i <= right && quickSortedArray[i] <= quickSortedArray[pivot] { i += 1 }
        while j > left &&  quickSortedArray[j] >= quickSortedArray[pivot] { j -= 1 }
        
        /*내림차순으로 구현하고 싶을 경우*/
        /*
         while i <= right && quickSortedArray[i] <= quickSortedArray[pivot] { i += 1 }
         while j > left &&  quickSortedArray[j] >= quickSortedArray[pivot] { j -= 1 }
    */
        
        if i > j {
            //i와 pivot간의 SWAP
            let temp = quickSortedArray[j]
            quickSortedArray[j] = quickSortedArray[pivot]
            quickSortedArray[pivot] = temp
        } else {
            //i와 j간의 SWAP
            let temp = quickSortedArray[j]
            quickSortedArray[j] = quickSortedArray[i]
            quickSortedArray[i] = temp
        }
    }
    
    quickSort(left, j - 1)
    quickSort(j + 1, right)
}

var mergeSortedArray = [Int]()
public func mergeSortSolution() {
    mergeSortedArray = array
    partition(0, mergeSortedArray.count - 1)
    print("[머지소트]: \(mergeSortedArray)")
}
mergeSortSolution()

/*머지소트: 가장 효율적인 알고리즘*/
//최선/평균/최악: O(logn)
//[분할]
public func partition(_ left: Int, _ right: Int) {
    guard left < right else { return }
    
    let mid = (left + right) / 2
    partition(left, mid)
    partition(mid + 1, right)
    merge(left, right)
}

//[정복]
public func merge(_ left: Int, _ right: Int) {
    var array2 = [Int](repeating: 0, count: mergeSortedArray.count)
    let mid = (left + right) / 2
    var i = left
    var j = mid + 1
    var k = left
    
    while i <= mid && j <= right {
        if mergeSortedArray[i] <= mergeSortedArray[j] {
            array2[k] = mergeSortedArray[i]
            i += 1
        } else {
            array2[k] = mergeSortedArray[j]
            j += 1
        }
        k += 1
    }
    
    var temp = i > mid ? j : i
    while k <= right {
        array2[k] = mergeSortedArray[temp]
        k += 1
        temp += 1
    }
    for index in left...right { mergeSortedArray[index] = array2[index] }
}

var heapSortedArray = [Int]()
public func heapSortSolution() {
    heapSortedArray = array
    
}
/*힙소트*/
//최선: O(n)
//평균/최악: O(nlogn)
public func heapSort(_ array: [Int]) -> [Int] {
    var array: [Int] = array
    
    return array
}

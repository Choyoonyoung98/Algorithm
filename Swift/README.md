# Algorithm

### 😐 그때그때 정리하는 문법
#### - 입력 방법  
```
let N = Int(readLine()!)
//공백을 기준으로 배열을 입력받아야 할 경우
times = readLine()!.split(separator: " ").map { Int($0)! }
```

#### - 배열 크기 초기화
```
var arr = [Int](repeating: 0, count: 3) // [0, 0, 0]
var arr2 = Array(repeating: 0, count: 3) //[0, 0, 0]
var arr3 = [[Int]](repeating: [Int](repeating: 1, count: 3), count: 3) // [[1,1,1],[1,1,1],[1,1,1]]
```

#### - [문자열 조작](Grammar/String.playground/Contents.swift)  

#### - 정렬
```
//오름차순
arr.sort()
//내림차순
arr.sort(by: >)

let newArr = arr.sorted()
```
#### - 고차함수
1. reduce
```
food_times.reduce(0, +)
```  

#### - 새로운 데이터 타입 선언  
```
var newInfo: [(time: Int, index: Int)]
```  
  
#### - enumerated   
$0에 index를, $1에 해당 index의 배열값에 접근할 수 있다  
```
var food_info: [(time: Int, index: Int)] = food_times.enumerated().map{($1, $0)}
```  

#### - 특정 구간을 담은 배열로 재정의  
```
food_info = food_info[i...]
food_info = food_info[...i]
```  

#### - stride  
a부터 b까지 p의 보폭으로 for문을 돌릴 수 있다.  
-> b를 포함하는 경우  
```
for j in stride(from: a, through: b, by: p) { }
```  
-> b를 포함하지 않는 경우  
```
for j in stride(from: a, to: b, by: p) { }
```   

#### - sqrt(), pow()
1. 제곱근: sqrt()  
```
let n = Int(sqrt(Double(x))
```  

2. 제곱: pow()  
```
func pow(_ x: Int, _ n: Int) -> Int {
    if n == 0 { return 1 }
    return x * pow(x, n-1)
}
```  

#### - 해당 숫자값 + 각 자리의 숫자 합 구하기

1)  
```
func divideSum(_ n: Int) -> Int {
    return String(n).reduce(n) { $0 + Int(String($1))! } //(*)
}
```

2)  
```
var result: Int = 0
while K > 0 {
    result += K % 10
    K /= 10
}
print(result)
```

#### - 시간 줄이기
1) 무분별한 고차함수 사용 줄이기
2) for문보다 forEach문 사용하기
3) 전역변수 사용 줄이기
4) 배열 입력받을 때  
`var inputList: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }`  
보다  
`var inputList: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }` 을 사용하면 입력 시간을 줄일 수 있다  

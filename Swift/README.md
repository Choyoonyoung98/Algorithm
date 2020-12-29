# Algorithm

### 😐 그때그때 정리하는 문법
#### - 입력 방법  
```
let N = Int(readLine()!)
//공백을 기준으로 배열을 입력받아야 할 경우
times = readLine()!.split(separator: " ").map { Int($0)! }
```

#### - [문자열 조작](String.playground/Contents.swift)  

#### - 정렬
```
//오름차순
arr.sort()
//내림차순
arr.sort(by: >)

let newArr = arr.sorted()
```
#### - 고차함수
1) ```food_times.reduce(0, +)```  

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

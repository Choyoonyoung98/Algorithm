# Algorithm

#### 😐기본 문법
- 입력 방법  
```
let N = Int(readLine()!)
//공백을 기준으로 배열을 입력받아야 할 경우
times = readLine()!.split(separator: " ").map { Int($0)! }
```

- [문자열 조작](String.playground/Contents.swift)  

- 정렬
```
//오름차순
arr.sort()
//내림차순
arr.sort(by: >)

let newArr = arr.sorted()
```

- 새로운 데이터 타입 선언
```var newInfo: [(time: Int, index: Int)]```  

- enumerated  
$0에 index를, $1에 해당 index의 배열값에 접근할 수 있다
```var food_info: [(time: Int, index: Int)] = food_times.enumerated().map{($1, $0)}```

- 특정 index부터의 원소로 다시 재정의  
```food_info = food_info[i...]```  

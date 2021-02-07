# Algorithm
c++문법 기반의 알고리즘 예제

#### 📌목표1: C 런타임 라이브러리 사용하지 않고 순수 C++ 런타임 라이브러리만을 사용, 각종 내장함수에 익숙해지기
#### 📌목표2: 코드리뷰를 하면서 실행시간 줄이려는 노력 해보기
#### 📌목표3: 제발 무작정 벡터 쓰지 말기

### 뭘 써야할까?

- 데이터의 존재 유무 만 궁금할 경우 → set

- 중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

- 데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

- 중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

- 속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map (insert, erase, find 모두 O(1)O(1). 최악의 경우엔 O(N)O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!)

<hr/>

#### 🤓라이브러리

✍🏻 [cmath](Grammar/cmath/cmath/main.cpp)
  - ceil: 올림
  - floor: 내림
  - abs: 절대값 반환
  - pow: 제곱값 반환
  - sqrt: 제곱근 반환
  - max: 최대값
  - max: 최소값
  
✍🏻 algorithm
  - sort
  - remove
  - lambda
  - transform
  - find
  
<hr/>

#### 😐기본 문법

👉🏻Basic
- [입/출력](Grammar/Input_Output/Input_Output/main.cpp)
- [함수 호출](Grammar/Function_Call/Function_Call/main.cpp)
- [이분 탐색 범위](Grammar/Bound.md)
  
👉🏻String
- [string 기본 함수](Grammar/String_Chars/String_Chars/main.cpp)
- [형 변환](Grammar/Type/Type/main.cpp)
- [Date <-> String 형변환](Grammar/ConvertBetweenDateAndString/ConvertBetweenDateAndString/main.cpp)  
- [정규식 확인](Grammar/ExpressionCheck/ExpressionCheck/main.cpp)

👉🏻Vector
- [벡터 기본1](Grammar/Vector_1/Vector_1/main.cpp)
- [벡터 기본2](Grammar/Vector_2/Vector_2/main.cpp)
- [Find](Grammar/Find/Find/main.cpp)
- [Remove, lambda,transform](Grammar/Remove/Remove/main.cpp)
- [Unique](Grammar/Unique/Unique/main.cpp)
- [Sort](Grammar/Sort/Sort/main.cpp)

👉🏻Map / Set
- [Set](Grammar/Set/Set/main.cpp)
- [Map](Grammar/Map/Map/main.cpp)
- [MultiSet, MultiMap](Grammar/MultiSet_Map/MultiSet_Map/main.cpp)
- [UnorderedSet, UnOrderedMap](Grammar/UnorderedMap_Set/UnorderedMap_Set/main.cpp)
- [UnOrderedMap VS Map](Grammar/MapDiff.md)

👉🏻[Linked List](Grammar/LinkedList/LinkedList/main.cpp)

👉🏻Stack
- [Stack](Grammar/Stack/Stack/main.cpp)

👉🏻Queue
- [Queue](Grammar/Queue/Queue/main.cpp)
- [Prority_Queue](Grammar/Priority_Queue/Priority_Queue/main.cpp)

**+) Priority Queue 연산** 
> struct 데이터를 우선순위 큐에 넣어 비교 연산이 가능하게 하고 싶을 경우
```
struct Point {
    int y;
    int x;
    int cost;
    
    Point(int _y, int _x, int _cost) {
        y = _y;
        x = _x;
        cost = _cost;
    };
    Point(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

bool operator < (Point a, Point b) { return a.cost > b.cost; }
```

<hr/>

### 문제 유형에 따른 알고리즘 채택
#### 1) Greedy 그리디
- [Greedy 알고리즘 자세히 알아보기](Theory/Greedy.md) 

#### 2) BFS / DFS
BFS란 너비 우선 탐색이고, DFS는 깊이 우선 탐색입니다.  
대부분의 상황에서 BFS가 DFS보다 효율적이므로, 가능하다면 BFS 시도하는 것이 바람직해보입니다.  

#### 3) 다이나믹 프로그래밍 Dynamic Programming
- [DP 더 자세히 알아보기](Theory/DP.md)

#### 4) 최단 경로 문제
그래프상에서 가장 짧은 경로를 찾는 알고리즘입니다.  
- [최단 경로 알고리즘 자세히 알아보기](Theory/ShortestPathProblem.md)  

#### 5) 그래프  
- [그래프 자세히 알아보기](Theory/Graph.md)  

#### 6) 부분집합
- [부분집합 자세히 알아보기](Theory/Subsest.md)

#### 7) 에라스토네스의 체
- [에라스토네스의 체](Theory/PrimeNumber.md)

#### 8) 비트 단위 연산자(Bitwise operators)
- [비트 마스크 자세히 알아보기](Theory/BitMask.md)

#### 9) DFS + Dijkstra
- [DFS + Dijkstra에 대해 알아보기](Theory/DFS_Dijkstra.md)

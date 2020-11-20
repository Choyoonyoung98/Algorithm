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

✍🏻 cmath <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/cmath/cmath/main.cpp">GO</a>
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
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Input_Output/Input_Output/main.cpp">입/출력</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Function_Call/Function_Call/main.cpp">함수 호출<a>
  
👉🏻String
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/String_Chars/String_Chars/main.cpp">string 기본 함수</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Type/Type/main.cpp">형 변환</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/ExpressionCheck/ExpressionCheck/main.cpp">정규식 확인</a>

👉🏻Vector
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Vector_1/Vector_1/main.cpp">벡터 기본1</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Vector_2/Vector_2/main.cpp">벡터 기본2</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Find/Find/main.cpp">Find</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Remove/Remove/main.cpp">Remove, lambda,transform</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Unique/Unique/main.cpp"> Unique</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Sort/Sort/main.cpp">Sort</a>

👉🏻Map / Set
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Set/Set/main.cpp">Set</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Map/Map/main.cpp">Map</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/MultiSet_Map/MultiSet_Map/main.cpp">MultiSet, MultiMap</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/UnorderedMap_Set/UnorderedMap_Set/main.cpp"> UnorderedSet, UnOrderedMap</a>

👉🏻Linked List
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/LinkedList/LinkedList/main.cpp">Linked List</a>

👉🏻Stack
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Stack/Stack/main.cpp">Stack</a>

👉🏻Queue
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Queue/Queue/main.cpp">Queue</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Grammar/Priority_Queue/Priority_Queue/main.cpp">Prority_Queue</a>

<hr/>

### 문제 유형에 따른 알고리즘 채택 [GO](/theory/Algorithm_Kinds.md)  
#### Greedy 그리디
그리디란, 현재 상황에서 **"지금  당장"** 좋은 것만 고르는 방법입니다.  

##### 문제 유형
- 주어진 숫자 리스트를 이용해 만들 수 없는 최소값 구하기
```
void solution() {
  sort(number.begin(), number.end());
  int target = 1; //만들 수 없는 최소값은 1원부터 시작하기 때문
  for(int i=0; i<number.size(); i++) {
    if(target<number[i]) return false;
    target += number[i];
  }
  return true;
}
```

- 중복된 수들을 포함한 숫자 2개 뽑기(단,뽑힌 숫자가 서로 중복되지 않게 해야한다.)
```
void solution() {
  cin>> N>> M;
  for(int i=0; i<N; i++) {
    int x =0;
    cin>> x;
    numb_cnt[x]++;
  }
  
  for(int i=1; i<=M; i++) {
    N -= numb_cnt[i];
    answer += numb_cnt[i] * N;
  }
}
```

#### 1) BFS / DFS
BFS란 너비 우선 탐색이고, DFS는 깊이 우선 탐색입니다.  
대부분의 상황에서 BFS가 DFS보다 효율적이므로, 가능하다면 BFS 시도하는 것이 바람직해보입니다.  

#### 2) 다이나믹 프로그래밍 Dynamic Programming
한 번 구한 결과를 메모리 공간에 메모해두고 같은 식을 다시 호출하면 메모한 결과를 그대로 가져오는 기법을 의미합니다.  
메모리 공간을 약가 더 사용하면 연산속도를 비약적으로 증가시킬 수 있는 방법입니다. 다이나믹 프로그래밍에는 **탑 다운(메모리제이션)**, **보텀업** 2가지 방식이 있습니다.  

이러한 다이나믹 프로그래밍을 해결할 수 있는 문재는  
1) **최적 부분 구조**: 큰 문제를 작은 문제로 나눌 수 있으며, 작은 문제의 답을 모아서 큰 문제 해결 가능한 구조인가?
2) **중복되는 부분 문제**: 동일한 작은 문제를 반복적으로 해결해야 하는지?

##### 문제 유형
1) 나아갈 선택지가 있고
2) 한쪽 방향으로만 나아가야할 때
3) 이전의 결과값을 이후에도 누적해서 활용해야할 때  
- [DP 더 자세히 알아보기](/Theory/DP.md)

#### 3) 최단 경로 문제
그래프상에서 가장 짧은 경로를 찾는 알고리즘입니다.  
- [최단 경로 알고리즘 자세히 알아보기](/Theory/ShortestPathProblem.md)  

#### 4) 그래프  
- [그래프 자세히 알아보기](/Theory/Graph.md)  

#### 5) 부분집합
- [부분집합 자세히 알아보기](/Theory/Subsest.md)


# Algorithm
c++문법 기반의 알고리즘 예제

### 뭘 써야할까?

- 데이터의 존재 유무 만 궁금할 경우 → set

- 중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

- 데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

- 중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

- 속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map (insert, erase, find 모두 O(1)O(1). 최악의 경우엔 O(N)O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!)

#### 😐기본 문법

👉🏻Basic
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Input_Output/Input_Output/main.cpp">입/출력</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Function_Call/Function_Call/main.cpp">함수 호출<a>

👉🏻Vector
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Vector_1/Vector_1/main.cpp">벡터 기본1</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Vector_2/Vector_2/main.cpp">벡터 기본2</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Find/Find/main.cpp">Find</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Remove/Remove/main.cpp">Remove, lambda,transform</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Unique/Unique/main.cpp"> Unique</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Sort/Sort/main.cpp">Sort</a>

👉🏻Map / Set
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Set/Set/main.cpp">Set</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Map/Map/main.cpp">Map</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/MultiSet_Map/MultiSet_Map/main.cpp">MultiSet, MultiMap</a>
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/UnorderedMap_Set/UnorderedMap_Set/main.cpp"> UnorderedSet, UnOrderedMap</a>

👉🏻Linked List
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/LinkedList/LinkedList/main.cpp">Linked List</a>

👉🏻Stack
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Stack/Stack/main.cpp">Stack</a>

👉🏻Queue
- <a href="https://github.com/Choyoonyoung98/Algorithm/blob/master/Queue/Queue/main.cpp">Queue</a>




## 탐욕 알고리즘(Greedy Algorithm)
Greedy Algorithm은 해답에 포함될 원소들을 차례로 선택하는 과정을 거치게 되는데, 각 단계에서는 전체적인 상황을 종합적으로 판단하고, 고려하여 결정하는 것이 아니라 **현 시점의 정보를 바탕으로 가장 이익이 되는 원소들을 선택하는 방법이라고 할 수 있다.**  

- 복잡한 과정을 거치지 않고, 상황을 종합적으로 판단하는 것이 아니기 때문에 매우 빠른 알고리즘. 
- `최적화 문제(optimization problem)`를 해결하기 위한 방법

Greedy Algorithm은 최적해를 구하기 위해 다음 3가지 작업을 수행한다.  
1. 선택작업: 현 상태에서 최적해에 포함시킬 대안을 선택
2. 타당성 조사: 선택된 해가 주어진 문제의 조건을 만족하는지 검사
3. 해답 조사: 원래의 문제가 해결되었는지를 조사  

```
greedy_method() {
  int answer = 0;
  
  while(condition) {
    s = select(); //원소 s를 선택
    if(feasible(s)) { //원소 s가 가능한 solution이라면
      solution = solution U {s}; //solution에 포함시킴
      if(problem_solved(solution)) return solution; //문제를 해결했을 때 solution 도출
      }
    }
}
```

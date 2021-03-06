## DP(Dynamic Programming)

한 번 구한 결과를 메모리 공간에 메모해두고 같은 식을 다시 호출하면 메모한 결과를 그대로 가져오는 기법을 의미합니다.  
메모리 공간을 약가 더 사용하면 연산속도를 비약적으로 증가시킬 수 있는 방법입니다. 다이나믹 프로그래밍에는 **탑 다운(메모리제이션)**, **보텀업** 2가지 방식이 있습니다.  

이러한 다이나믹 프로그래밍을 해결할 수 있는 문재는  
1) **최적 부분 구조**: 큰 문제를 작은 문제로 나눌 수 있으며, 작은 문제의 답을 모아서 큰 문제 해결 가능한 구조인가?
2) **중복되는 부분 문제**: 동일한 작은 문제를 반복적으로 해결해야 하는지?

##### 문제 유형
1) 나아갈 선택지가 있고
2) 한쪽 방향으로만 나아가야할 때
3) 이전의 결과값을 이후에도 누적해서 활용해야할 때  
### 최장 증가 부분 수열1 `O(n^2)`  
앞에서 뒤로 숫자를 선택하며 부분 수열을 구성해 나갈 때 **증가하는 순서대로 숫자를 고르면서** 고른 **부분 수열의 길이가 최대**가 되도록 숫자를 선택하는 경우입니다.  
```
int[N] array; //인덱스마다 각 입력값
int [N] dp; //인덱스마다 각 증가 수열의 길이

int max = 0;
dp[0][ = 1;

for(int i=1; i<N; i++) {
  dp[i] = 1;
  for(int j=0; j<i; j++) {]
    if(array[i] > array[j] && dp[j]+1 > dp[i]) {
      dp[i] = dp[j] +1;
    }
  }
  
  if(nax < dp[i]) max = dp[i];
}
```  
하나를 기준으로 잡아 그 전에 값들을 비교해서 길이를 정하는 방식입니다.  
기본적으로 어찌됐든 길이는 1로 시잓합니다.  
당연히 array[i]가 array[j]보다 커야하고, **길이를 증가할 수 있는지** 에 대한 조건을 주게 됩니다.  
> dp를 사용할 때 가장 중요한 것은 dp에 어떤 정보를 담을 것인지이다.

### 최장 증가 부분 수열2 `O(nlogn)`  
리스트의 크기가 10만보다 클 경우에는 O(n^2)의 시간복잡도를 가지게 될 경우 시간 초과를 하게된다. 따라서 해당 방법을 사용해야 한다.  
```
dp[0] = array[0];
int idx = 0;
for(int i=1; i<n; i++) {
  if(dp[idx] < array[i]) {
    dp[++idx] = array[i];
   }
 }
}
```  

### 최소 편집 거리 계산
두 개의 문자열이 같아지기 위해서 몇 번의 **추가** , **삭제** , **편집** 이 이루어져야 하는지 그 최소 개수를 구하는 알고리즘입니다.  
쉽게 말하여 두 문자열의 유사도를 수치화하여 나타낼 수 있기 때문ㅇ데 아주 유용하게 활용될 수 있습니다. 이러한 문제는 동적 프로그래밍을 이용해 쉽게 해결할 수 있습니다.  
- 단어 추가: 왼쪽에 1을 더하기
- 단어 편집: 왼쪽 위에 1을 더하기
- 단어 삭제: 위쪽에 1을 더하기  

```
int levenshtein(string& input1, string& input2) {
  for(int i=1; i<=input1.size(); i++) dist[i][0] = i;
  for(int i=1; i<=input2.size(); i++) dist[0][i] = i;
  
  for(int i=1; i<=input1.size(); i++) {
    for(int j=1; j<=input2.size(); j++) {
      if(input1[i-1] == input2[j-1]) dist[i][j] = dist[i-1][j-1];
      else dist[i][j] = min(dist[i-1][j-1]+1, min(dist[i][j-1]+1, dist[i-1][j]+1));
    }
   }
   
   return dp[input1.size()][input2.size()]
 }
```

1) `if(input1[i-1] == input2[j-1])`
- 두 변수가 일치했을 경우 이전의 편집거리를 가져온다.  
- D(i,j) = D(i-1, j-1)이다.  

2) 일치하지 않았을 경우,
- 이전의 편집거리에서 코스트를 하나 증가시켜주면 된다.  
- D(i,j) = min(D(i-1, j)+1, D(i, j-1)+1, D(i-1,j-1)+1)이다.  


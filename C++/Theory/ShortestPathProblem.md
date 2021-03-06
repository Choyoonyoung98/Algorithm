## 최단 경로 알고리즘 Shortest Path Problem
**최단 경로가 아닌 최단 거리를 구하는 알고리즘**  

### 플로이드 워셜 `O(n^3)` **3중 포문**  
그래프애서 **모든 꼭짓점 사이의 최단 경로** 의 거리를 구하는 알고리즘입니다.  
```
for(int k=0; k<N; k++) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(dp[i][j] > d[i][k]+d[k][j]) {
        dp[i][j] = d[i][k] + d[k][j];
     }
   }
}
      
```
### 다익스트라 `O(ElogV)` **우선순위 큐**  
다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘으로, **하나의 정점** 에서 **다른 모든 정점** 들의 최단 경로를 구합니다.  
한 단계당 하나의 노드에 대한 최단 거리를 확실히 찾는 것으로 이해할 수 있습니다.  

#### 우선순위 큐를 사용하는 이유는 무엇일까?
> 결론적으로 최소거리 값 갱신 횟수의 증가 때문입니다. 일반 큐를 써도 결과값은 같지만 우선순위큐를 사용하면 속도에 이점이 있기 때문입니다.  
다익스트라 알고리즘에서 속도에 영향을 주는 요소는 **큐에서 노드를 꺼내오는 횟수** 와 **우선순위 큐의 갱신 횟수** 입니다. 우선순위큐를 사용하면 이전에 계산해둔
값이 그 단계에서 최소값이라는 것이 보장되기 때문에 값의 갱신 횟수가 일반 큐에 비해 현저히 적어집니다.  
그래서 우선순위 큐를 사용시에는 O(ElogV)라는 시간상의 이점이 발생합니다.  
```
void dijkstra(int source) {
    d[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        if(d[index] < cost) continue;
        for(int i=0; i<graph[index].size(); i++) {
            int nextCost = cost + graph[index][i].first;
            int nextIndex = graph[index][i].second;
            if(d[nextIndex] > nextCost) {
                d[nextIndex] = nextCost;
                pq.push({nextCost, nextIndex});
            }
        }
    }
}
```



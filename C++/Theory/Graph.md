## 그래프 Graph

### 서로소 집합
집합은 공통 원소가 없는 두 집합입니다. 이때 **집합 간의 관계** 를 파악하기 위해서 서로소 집합 알고리즘을 사용할 수 있는데,  
서로소 집합 알고리즘 union-find 연산으로 구성되며, 모든 노드는 자신이 속한 집합을 찾을 때 루트 노드를 재귀적으로 찾습니다.  
서로소 집합 알고리즘은 최소 신장 트리를 찾는 크루스칼 알고리즘에서 사용되기도 하므로 중요합니다.  

서로소 집합 자료구조는 **union** 과 **find**, 이 2개의 연산으로 조작할 수 있습니다.  
- fnd: 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산 -> A와 B의 루트 노드 A`와 B`를 각각 찾습니다.  
- union: 2개의 원소가 포함된 집합을 하나의 집합으로 합치는 연산 -> A`를 B`의 부모 노드로 설정합니다. (B`가 A`를 가르키도록 합니다.)  

```
for(int i=1; i<=N; i++) parent[i] = i;

//Find 함수: 함수 x로 들어온 원소의 루트 노드를 반환
int find(int x) {
  if(x == parent[x]) return x;
  else {
    parent[x] = find(parent[x]);
    return parent[x];
  }
}

//Union 함수: x원소와 y원소를 합치는 함수로 y의 루트 노드를 x로 변환
void union(int x, int y) {
  x = find(x);
  y = find(y);
  
  if(x != y) parent[y] = x;
}
```

-> 문제유형
1. 현재 서로 연결되어 있는 경로 정보를 제공하고
2. 그 경로에서 가고자 하는 부분 경로의 순서가 주어진다면 [2->3->4->3]
//경로 연결 정보 + 경로 이동 계획이 주어진다면? => 서로소 집합 Union-Set

### 신장 트리
신장 트리는 하나의 그래프가 있을 때 모든 노드를 포함하는 부분 그래프를 의미합니다.  
이러한 신장 트리 구성 문제는 현실 세계에서 '모든 섬을 도로를 이용해 연결하는 문제' 등에서 사용할 수 있습니다.  

#### 크루스칼 알고리즘 `O(ElogE)` DisjointSet
크루스칼 알고리즘은 가능한 최소 비용의 신장 트리를 찾아주는 알고리즘입니다.  
간선을 정렬한 뒤에 간선의 비용이 작은 순서대로 차례대로 최소 신장 트리를 만들어 가는 그리디 알고리즘의 일종입니다.  

이러한 크루스칼 알고리즘은 Union-Find 알고리즘을 활용합니다.  

##### 알고리즘 로직
1) 간선 데이터를 비용에 따라 오름차순으로 정렬합니다.  
2) 간선을 하나씩 확인하여 현재의 간선이 사이클을 발생시키는지 확인합니다.  
  2-1) 사이클이 발생하지 않는 경우 최소 신장 트리에 포함시킵니다.  
  2-2) 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않습니다.  
3) 모든 간선에 대해서 2번의 과정을 반복합니다.  
```
int findParent(int x) {
  if(x == parent[x]) return x;
  parent[x] = findParent(parent[x]);
  return parent[x];
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a<b) parent[b] = a;
  else parent[a] = b;
}
```

```
//부모 테이블상에서, 부모를 자기 자신으로 초기화
for(int i=1; i<= V; i++) parent[i] = i;

for(int i=0; i<E; i++) {
  int a,b,const;
  edges.push_back({cost, {a,b}};
}
sort(edges.begin(), edges.end()); //간선을 비용에 대해 오름차순으로 정렬

//모든 간선에 대해서 체크
for(int i=0; i<edges.size(); i++) {
  int const = edges[i].first;
  int a = edges[i].second.first;
  int b = edges[i].second.second;
  
  if(findParent(a) != findParent(b)) {
    unionParent(a,b);
    result += cost;
  }
}
```

### 위상 정렬 알고리즘 `O(V+E)` Queue
위상 정렬 알고리즘은 방향그래프의 모든 노드들을 방향성에 거스르지 않도록 **순서대로 나열** 하는 정렬 기법을 의미합니다.  
예를 들어 '선수 과목을 고려한 학습 순서 설정 문제' 등에서 사용될 수 있습니다. 

#### 언제 사용할까? **커리큘럼** **선수 과목**
- 사이클이 없고
- 순서가 정해져있는

#### 알고리즘의 로직
1) 진입차수가 0인 노드를 큐에 넣습니다.  
2) 큐가 empty()될 때까지 아래의 과정을 반복합니다.  
 2-1) 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거합니다.  
 2-2) 새롭게 진입차수가 0이 된 노드를 큐에 넣습니다.

#### 특징
- 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다고 판단.
- 위상정렬에는 여러가지 답이 존재 가능.

```
int inDegree[MAX_SIZE];
vector<int> a(MAX_SIZE, 0);
queue<int> q;

for(int i=1; i<=N; i++) {
  if(inDegree[i] == 0) q.push(i); //진입차수가 0인 노드는 큐에 삽입
}

//위상 정렬이 완전히 수행되려면 정확히 N개의 노드 방문해야함
for(int i=1; i<=N; i++) {
  //n개의 노드를 방문하기 전에 큐가 비면 사이클 발생
  if(q.empty()) return;
  
  int x = q.front();
  q.pop();
  result[i] = x; //큐의 가장 앞 원소를 빼서 result 배열에 넣어준다.
  
  //꺼낸 원소에 연결되어 있는 모든 정점들을 확인하면서 간선을 제거
  for(int i=0; i<a[x].size(); i++) {
    int y = a[x][i];
    
    if(--inDegree[y] == 0) q.push(y); //진입차수가 0인 노드 큐에 삽입
  }
}
```

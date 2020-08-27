## Trie(트라이)
트라이는  **문자열에서의 검색을 빠르게 해주는 자료구조** 입니다.   

우리는 **정수형 자료형** 에 대해서 이진검색 트리를 이용하면 `O(logN)`의 시간만에 원하는 데이터를 검색할 수 있습니다.  
하지만, **문자열**  에서 이진검색트리를 사용한다면 문자열의 최대 길이가 M이라면 `O(MlogM)`의 시간복잡도를 가지게 될 것입니다.  

우리는 문자열에서의 검색을 개선하기 위하여 트라이를 이용하여 O(M)의 시간만에 원하는 문자열을 검색할 수 있습니다.  
트라이라는 명칭은 Retrieval에서 유래했는데, 트라이가 retrieve(탐색)하는데 유용한 걸 생각하면 납득이 됩니다.  

예를 들어 문자열 집합 = {"AE", "ATV", "ATES", "ATEV", "DE", "DC"}가 존재할 때 트라이는 다음과 같이 형성이 됩니다.  
(트라이 예시)[../Trie.jpeg]!

이 경우 트리형태를 띄는 트라이에서 검색을 할 경우 최대 트리의 높이까지 탐색하게 됩니다.  
따라서 시간복잡도는 O(H)가 됩니다. 하지만 트리의 높이는 최대 문자열의 길이가 되기 때문에 O(M)의 시간복잡도에 문자열 검색이 가능한 것입니다.  

```
struct Trie {
  Trie* next[10];
  bool term;
  Trie(): term(false) {
    memset(next, 0, sizeof(next));
  }
  
  ~Trie() {
    for(int i=0; i<10; i++) {
      if(next[i]) delete next[i];
    }
  }
  
  void insert(const char* key)  {
    if(*key == '\0') term = true;
    else {
      int curr = *key - '0';
      if(next[curr] == NULL) next[curr] = new Trie();
      next[curr]->insert(key+1);
    }
  }
  
  bool find(const char* key) {
    if(*key == '\0') return 0;
    if(term) return 1;
    int curr = *key - '0';
    return next[curr]->find(key+1);
  }
}
```

### 문제 예시
1. 가사 검색: https://programmers.co.kr/learn/courses/30/lessons/60060
2. 전화번호 목록: https://www.acmicpc.net/problem/5052

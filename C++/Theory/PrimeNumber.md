### 에라스토네스의 체  

```
void solution(int n) {
    bool visited[MAX_SIZE];
    fill(visited, visited+MAX_SIZE, true);
    for(int i=2; i<=sqrt(double(n)); i++) {
        if(!visited[i]) { continue; }
        for(int j = i*i; j<=n; j += i) {
            visited[j] = false;
        }
    }
    
    for(int i=2; i<=n; i++) {
        if(visited[i]) { cout<<i << endl;}
    }
}
```

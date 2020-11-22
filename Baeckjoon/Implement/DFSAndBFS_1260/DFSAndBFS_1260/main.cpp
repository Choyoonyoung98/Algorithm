//
//  main.cpp
//  DFSAndBFS_1260
//
//  Created by 조윤영 on 2020/11/22.
//
//DFS와 BFS
//NOTE: BFS 기본적인 이론에 충실하기! DFS와 BFS의 차이점 확실히 머릿속에 명시해두기
//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M, V = 0;
vector<vector<int>> edges;
vector<bool> visited;
void input() {
    cin>> N>>M>>V;
    edges.assign(N+1, {});
    visited.assign(N+1, false);
    for(int i=0; i<M; i++) {
        int a, b = 0;
        cin>> a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for(int i=1; i<=N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
}

void DFS(int idx) {
    visited[idx] = true;
    cout<<idx<<" ";
    for(int i=0; i<edges[idx].size(); i++) {
        if(!visited[edges[idx][i]]) {
            DFS(edges[idx][i]);
        }
    }
}

struct Graph {
    int idx;
    int cnt;
    Graph(int _idx, int _cnt) {
        idx = _idx;
        cnt = _cnt;
    };
};

void BFS() {
    queue<Graph> q; //idx, cnt
    visited[V] = true;
    q.push(Graph(V, 1));
    while(!q.empty()) {
        int idx = q.front().idx;
        int cnt = q.front().cnt;
        q.pop();
        
        cout<<idx<<" ";
        if(cnt == N) return;
        
        for(int i=0; i<edges[idx].size(); i++) {
            int nextIdx = edges[idx][i];
            if(!visited[nextIdx]) {
                q.push(Graph(nextIdx, cnt+1));
                visited[nextIdx] = true;
            }
        }
        
    }
}

void solution() {
    DFS(V);
    cout<<"\n";
    visited.assign(N+1, false);
    BFS();
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

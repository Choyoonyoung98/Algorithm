//
//  main.cpp
//  ShortestPath_1753
//
//  Created by 조윤영 on 2020/11/23.
//https://www.acmicpc.net/problem/1753
//
//최단 경로

#define INF 1e9
#define MAX_SIZE 20001
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int V, E, K;
vector<vector<pair<int,int>>> graph;
int d[MAX_SIZE];
void input() {
    cin>> V >> E;
    cin>> K;
    fill(d, d+V+1, INF);
    graph.assign(V+1, {});
    int u, v, w = 0;
    for(int i=0; i<E; i++) {
        cin>> u >> v >> w;
        graph[u].push_back({w, v});
    }
}

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

void solution() {
    dijkstra(K);
    for(int i=1; i<=V; i++) {
        if(i == K) cout<<"0\n";
        else {
            if(d[i] == INF) cout<<"INF\n";
            else cout<<d[i]<<"\n";
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

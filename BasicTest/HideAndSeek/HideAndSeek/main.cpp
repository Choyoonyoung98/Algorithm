//
//  main.cpp
//  HideAndSeek
//
//  Created by 조윤영 on 2020/09/03.
//  Copyright © 2020 조윤영. All rights reserved.
//
//숨바꼭질

#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 20001
#define INF 50001

using namespace std;

int N, M = 0;
vector<vector<int>> passage;
int d[MAX_SIZE];

void input() {
    cin>> N>> M;
    passage.assign(N+1, vector<int>(N+1, INF));
    int A,B = 0;
    for(int i=0; i<M; i++) {
        cin>> A>>B;
        passage[A][B] = 1;
        passage[B][A] = 1;
    }
}

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    d[1] = 0;
    
    while(!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(d[node] < dist) continue;
        
        for(int i=1; i<=N; i++) {
            int cost = dist + passage[node][i];
            if(cost < d[i]) {
                d[i] = cost;
                pq.push({cost, i});
            }
        }
    }
}

void solution() {
    fill(d, d+MAX_SIZE, INF);
    dijkstra();
    
    int maxNode = 0;
    int maxDistance = 0;
    vector<int> sameDistanceNodes;

    for(int i=1; i<=N; i++) {
        if(maxDistance < d[i]) {
            maxNode = i;
            maxDistance = d[i];
            sameDistanceNodes.clear();
            sameDistanceNodes.push_back(i);
        } else if(maxDistance == d[i]) sameDistanceNodes.push_back(i);
    }
    
    cout<<maxNode<<" "<<maxDistance<<" "<<sameDistanceNodes.size()<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    return 0;
}

/*
 6 7
 3 6
 4 3
 3 2
 1 3
 1 2
 2 4
 5 2
 */

//
//  main.cpp
//  MarsExploration
//
//  Created by 조윤영 on 2020/09/03.
//  Copyright © 2020 조윤영. All rights reserved.
//
//화성 탐사
//다익스트라 알고리즘?

#include <iostream>
#include <queue>
#define MAX_SIZE 126
#define INF 1e9
using namespace std;
int solution();
int T= 0;
int N = 0;
int room[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE][MAX_SIZE];
struct Dir {
    int y;
    int x;
    
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void input() {
    cin>>T;
    for(int t=0; t<T; t++) {
        cin>>N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) cin>> room[i][j];
        }
        
        cout<<solution()<<"\n";
    }
}

bool canMoveTo(int y, int x) {
    if(0<= y && y<N && 0<= x && x<N) return true;
    return false;
}

int solution() {
    for(int i=0; i<N; i++) fill(d[i], d[i]+125, INF);
    
    int y = 0;
    int x = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    //가장 최단거리가 짧은 노드를 우선적으로 탐색하기 위해
    pq.push({room[y][x], {y, x}});
    d[y][x] = room[y][x];
    
    while(!pq.empty()) {
        int dist = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(d[y][x] < dist) continue; //현재 노드가 이미 처리된 적이 있는 노드라면 무시
        
        for(int i=0; i<4; i++) {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            
            if(canMoveTo(nextY, nextX)) {
                int cost = dist + room[nextY][nextX];
                if(cost < d[nextY][nextX]) {
                    d[nextY][nextX] = cost;
                    pq.push({cost, {nextY, nextX}});
                }
            }
        }
    }
    return d[N-1][N-1];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    return 0;
}

/*
 3
 3
 5 5 4
 3 9 1
 3 2 7
 5
 3 7 2 0 1
 2 8 0 9 1
 1 2 1 8 1
 9 8 9 2 0
 3 6 5 1 5
 7
 9 0 5 1 1 5 3
 4 1 2 1 6 5 3
 0 7 6 1 6 8 5
 1 1 7 8 3 2 3
 9 4 0 7 6 4 1
 5 8 3 2 4 8 3
 7 4 8 4 8 3 4
 */

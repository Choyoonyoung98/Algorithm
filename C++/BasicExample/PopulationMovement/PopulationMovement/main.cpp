//
//  main.cpp
//  PopulationMovement
//
//  Created by 조윤영 on 2020/08/23.
//  Copyright © 2020 조윤영. All rights reserved.
//
//이거 통과 안함

##include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 51
using namespace std;

int N, L, R = 0;
int room[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

struct Dir {
    int y;
    int x;
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void input() {
    cin>> N>> L>> R;
    int x = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>> x;
            room[i][j] = x;
        }
    }
}

bool isAvailable(int y, int x) {
    if(0<=y && y<N && 0<=x && x<N) return true;
    return false;
}

bool isDifferInBoundary(int y1, int x1, int y2, int x2) {
    int A = room[y1][x1];
    int B = room[y2][x2];
    if(L <= abs(A-B) && abs(A-B) <=R) return true;
    return false;
}

bool BFS(int y, int x) {
    int cnt = 0;
    int sum = 0;
    queue<pair<int,int>> q;
    vector<pair<int,int>> unions;
    
    q.push({y,x});
    unions.push_back({y,x});
    visited[y][x] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        sum += room[y][x];
        cnt++;
        for(int d=0; d<4; d++) {
            int nextY = y + moveDir[d].y;
            int nextX = x + moveDir[d].x;
            
            if(isAvailable(nextY, nextX) && isDifferInBoundary(y, x, nextY, nextX) && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                unions.push_back({nextY, nextX});
                q.push({nextY, nextX});
            }
        }
    }
    
    if(unions.size() == 1) return false;
    
    for(int i=0; i<unions.size(); i++) {
        int y = unions[i].first;
        int x = unions[i].second;
        
        room[y][x] = sum/ cnt;
    }
    return true;
}

int solution() {
    int answer = 0;
    while(true) {
        bool isMove = false;
        for(int i=0; i<N; i++) fill(visited[i], visited[i]+N, false);
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(!visited[i][j] && BFS(i, j)) isMove = true;
            }
        }
        if(!isMove) return answer;
        answer++;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    
    return 0;
}

/*
2 20 50
50 30
20 40

2 40 50
50 30
20 40

2 20 50
50 30
30 40

3 5 10
10 15 20
20 30 25
40 22 10

4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/

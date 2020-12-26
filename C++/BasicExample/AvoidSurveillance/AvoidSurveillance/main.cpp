//
//  main.cpp
//  AvoidSurveillance
//
//  Created by 조윤영 on 2020/08/23.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/18428
//

#include <iostream>
#include <vector>
#define MAX_SIZE 7
#define SABOTAGE_MAX_SIZE 3
using namespace std;

int  N = 0;
char  room[MAX_SIZE][MAX_SIZE];
struct Dir {
    int y;
    int x;
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>>  teacher;
void input()  {
    cin>> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>> room[i][j];
            if(room[i][j] == 'T') teacher.push_back({i,j});
        }
    }
}

bool isAvailable(int y, int x) {
    if(0<= y && y< N && 0<= x && x< N) return true;
    return false;
}

bool canAvoidSurveliance() {
    for(int i=0; i<teacher.size(); i++) {
        int y = teacher[i].first;
        int x = teacher[i].second;
        for(int i=0; i<4; i++) {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            
            while(isAvailable(nextY, nextX)) {
                if(room[nextY][nextX] == 'O') break;
                else if (room[nextY][nextX] == 'S') return false;
                nextY += moveDir[i].y;
                nextX += moveDir[i].x;
            }
        }
    }
    return true;
}

bool canAvoid = false;
//bool visited[MAX_SIZE][MAX_SIZE];
void makeSabotage(int cnt) {
    if(cnt ==  SABOTAGE_MAX_SIZE) {
        if(canAvoid) return;
        if(canAvoidSurveliance()) canAvoid = true;

         return;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(room[i][j] == 'X') {
                room[i][j] = 'O';
                makeSabotage(cnt+1);
                room[i][j] = 'X';
            }
        }
    }
}

void solution() {
    makeSabotage(0);
    if(canAvoid) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

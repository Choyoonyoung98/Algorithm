//
//  main.cpp
//  Labatory_14502
//
//  Created by 조윤영 on 04/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//BFS + DFS

//1.벽을 세운다->2.바이러스를 퍼트린다.
//3.안전구간을 구한다.

//cstring - memcpy: 배열 복사
//어떤 배열 개념을 계속해서 다르게 쓴다면 복사를 생각해보기
//참조할 때에는 무조건 다시 새로운 변수에 저장하여 사용하기

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>


#define MAX_SIZE 10

using namespace std;

int N = 0;
int M = 0;
int room[MAX_SIZE][MAX_SIZE];
int temp[MAX_SIZE][MAX_SIZE];

queue<pair<int,int>> virus;

int maxSafeArea = 0;
int safeArea = 0;

int wallCnt = 3;
int virusCnt = 0;

struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>> N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>> room[i][j];
            
            if(room[i][j] == 2) {
                virus.push({i,j});
                virusCnt++;
            }
            if(room[i][j] == 0) safeArea++;
        }
    }
    
}

bool canSpread(int y, int x) {
    if(0<=y && y<N && 0<=x && x<M)return true;
    return false;
}


void spreadVirus(int& zeroCnt) {
    
    //BFS
    int afterWall[MAX_SIZE][MAX_SIZE];
    memcpy(afterWall, temp, sizeof(temp));

    queue<pair<int,int>> q = virus;
    
    int zero = zeroCnt;
    
    while(!q.empty()) {
        int currentY = q.front().first;
        int currentX = q.front().second;
 
        q.pop();
        
        
        for(int i=0; i<4; i++) {
            int nextY = currentY + moveDir[i].y;
            int nextX = currentX + moveDir[i].x;
            if(canSpread(nextY, nextX) && afterWall[nextY][nextX] == 0) {
                afterWall[nextY][nextX] = 2;
                zero--;
                q.push({nextY, nextX});
            }
        }
        
    }
   
    maxSafeArea = max(maxSafeArea, zero);
}

void makeWall(int cnt, int& zeroCnt) {
    //DFS
    if(cnt == wallCnt) {
        spreadVirus(zeroCnt);
        return;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(temp[i][j] == 0) {

                temp[i][j] = 1;
                zeroCnt--;
                
                makeWall(cnt+1, zeroCnt);
                
                temp[i][j] = 0;
                zeroCnt++;
            }
        }
    }
}

void solution() {
    
    //전체를 훑으면서 벽 세울 수 있는 후보 공간인 빈 공간 0을 찾아내어 벽을 세운다.
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(room[i][j] == 0) {
                //0 발견 시 연구실 상태를 복사한다.
                memcpy(temp, room, sizeof(room));
                
                temp[i][j] = 1;//벽을 세운다.
                safeArea--;//안전 구간 -1

                makeWall(1, safeArea); //현재 지어진 벽의 수를 넘기면서 나머지 벽을 세운다.
                
                temp[i][j] = 0;
                safeArea++;
                
                
            }
        }
    }
    
    cout<<maxSafeArea<<"\n";
    
   
}


int main(int arg, const char * argv[]) {
    input();
    solution();
    return 0;
}

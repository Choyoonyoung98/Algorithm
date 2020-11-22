//
//  main.cpp
//  AirPollution_17144
//
//  Created by 조윤영 on 15/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/17144

//때로는 가장 단순하게 접근하는 것이 정답이다.

#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

struct Dir {
    int y;
    int x;
};

Dir moveUpperDir[4] = {{0,1},{-1,0},{0,-1},{1,0}};//우 상 좌 하
Dir moveLowerDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};//우 하 좌 상

int R = 0;
int C = 0;
int T = 0;
int airCleanerX = 0;

int airCleaner1Y = -1;
int airCleaner2Y = -1;

int airPolutionCnt = 0;

int room[MAX_SIZE][MAX_SIZE];


queue<pair<int,int>> airPolution;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>R>>C>>T;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>> room[i][j];
            if(room[i][j] !=-1 && room[i][j] != 0) {
                airPolution.push({i,j});
                airPolutionCnt += room[i][j];
            }else if(room[i][j]==-1) {
                if(airCleaner1Y ==-1)airCleaner1Y = i;
                else airCleaner2Y = i;
            }
        }
    }
}

bool canSpread(int y,int x) {
    if(0<=y && y<R && 0<=x && x<C && room[y][x] !=-1)return true;
    
    return false;
}

void spread() {
    
    int cpy_room[MAX_SIZE][MAX_SIZE];
    memcpy(cpy_room, room, sizeof(room));
    
    int airPolutionCnt = airPolution.size();
    while(airPolutionCnt--) {

        
        int currentY = airPolution.front().first;
        int currentX = airPolution.front().second;
        
        
        airPolution.pop();
        
        int spread = cpy_room[currentY][currentX]/5;

        
        for(int i=0; i<4; i++) {
            int nextY = currentY + moveUpperDir[i].y;
            int nextX = currentX + moveUpperDir[i].x;
            
            if(canSpread(nextY, nextX)){

                room[nextY][nextX] += spread;
                room[currentY][currentX] -= spread;
            }

        }
        
       
    }
}

bool isInBoundary(int y,int x) {
    if(0<=y && y<R && 0<=x && x<C)return true;
    return false;
}

int wind1Y = 0;
int wind2Y = 0;
int wind1X = 0;
int wind2X = 0;

int temp1 = 0;
int temp2 = 0;


int dir1 = 0;
int dir2 = 0;

bool blowUpperWind(int windY, int windX, int temp, int dir) {
    
    if(room[windY][windX] == -1) {
        //공기청정기에 미세먼지가 들어갔다면
        airPolutionCnt -= temp;
        return false;

    }
    
    //이전 미세먼지 저장하기
    //다음 장소에 저장할 미세먼지 저장하기
    
    int storage = room[windY][windX];
    room[windY][windX] = temp;
    temp = storage;
//    cout<<storage<<endl;
    
    int nextWindY = windY + moveUpperDir[dir].y;
    int nextWindX = windX + moveUpperDir[dir].x;
    
    //다음 위치가 범위 밖이라면 방향 전환
    if(!isInBoundary(nextWindY, nextWindX)){
        dir = (dir+1)%4;
        nextWindY = windY + moveUpperDir[dir].y;
        nextWindX = windX + moveUpperDir[dir].x;
    }
    
    temp1 = temp;
    dir1 = dir;
    wind1Y = nextWindY;
    wind1X = nextWindX;
    
    return true;
}

bool blowLowerWind(int windY, int windX, int temp, int dir) {

    if(room[windY][windX] == -1) {
        //공기청정기에 미세먼지가 들어갔다면
        airPolutionCnt -= temp;
        
        return false;

    }
    
    
    //이전 미세먼지 저장하기
    //다음 장소에 저장할 미세먼지 저장하기

    int storage = room[windY][windX];
    room[windY][windX] = temp;
    temp = storage;
    
    
    int nextWindY = windY + moveLowerDir[dir].y;
    int nextWindX = windX + moveLowerDir[dir].x;
    
    //다음 위치가 범위 밖이라면 방향 전환
    if(!isInBoundary(nextWindY, nextWindX)){
        dir = (dir+1)%4;
        nextWindY = windY + moveLowerDir[dir].y;
        nextWindX = windX + moveLowerDir[dir].x;
    }
    
    temp2 = temp;
    dir2 = dir;
    wind2Y = nextWindY;
    wind2X = nextWindX;
    
    return true;
}

void purify() {

    while(true) {
        
        //위쪽 공기청정기
        if(!blowUpperWind(wind1Y, wind1X, temp1, dir1))break;
    }
    
    while(true) {
        //아랫쪽 공기청정기
        if(!blowLowerWind(wind2Y, wind2X, temp2, dir2))break;
    }
        
}

void solution() {
    
    
    
    for(int i=0; i<T; i++) {
        
        wind1Y = airCleaner1Y;
        wind2Y = airCleaner2Y;
        wind1X = airCleanerX+1;
        wind2X = airCleanerX+1;
        temp1 = 0;
        temp2 = 0;
        dir1 = 0;
        dir2 = 0;
        
        //1: 미세먼지 확산
        spread();

        //2: 정화
        purify();

        
        for(int i=0; i<R;i++) {
            for(int j=0; j<C; j++) {
                if(room[i][j] != -1 && room[i][j] !=0)airPolution.push({i,j});
            }
        }
        
        
    }
    cout<<airPolutionCnt<<"\n";
    
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}

//2 8 3 3

//
//  main.cpp
//  Snake
//
//  Created by 조윤영 on 2020/08/16.
//  Copyright © 2020 조윤영. All rights reserved.
//
//뱀
#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 101

using namespace std;

struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{1,0},{0,-1},{-1,0},{0,1}}; // 하 좌 상 우
int room[MAX_SIZE][MAX_SIZE];
int N = 0;
int K = 0;
int L =  0;
queue<pair<int, char>> directions;
queue<pair<int,int>> snakes;

void input() {
    cin>> N;
    cin>> K;
    
    memset(room, 0, N+1);
    
    int appleY = 0;
    int appleX = 0;
    
    for(int i=0; i<K; i++) {
        cin>> appleY >> appleX;
        room[appleY-1][appleX-1] = 1;
    }
    cin>> L;
    
    int time = 0;
    char dir;
    
    for(int i=0; i<L; i++) {
        cin>> time >> dir;
        directions.push({time,dir});
    }
}

bool checkIsInBoundary(int y, int x) {
    if( 0<= y && y < N && 0<= x && x < N) return true;
    return false;
}

bool checkMyBody(int y, int x) {
    if(room[y][x]  != 3) return true;
    return false;
}

int solution() {
    int currentY = 0;
    int currentX = 0;
    int currentDir = 3;
    
    int time = 0;
    while(true) {
        int nextY = currentY + moveDir[currentDir].y;
        int nextX = currentX + moveDir[currentDir].x;
        
        if(!snakes.empty() && room[currentY][currentX] != 1) {
            int endY = snakes.front().first;
            int endX = snakes.front().second;
            
            room[endY][endX] =  0;
            snakes.pop();
        }
        snakes.push({currentY, currentX});
        room[currentY][currentX] = 3;
        
        time++;
        
        if(checkIsInBoundary(nextY, nextX) && checkMyBody(nextY, nextX)) {
            currentY = nextY;
            currentX = nextX;
        } else return time;
        
        if(time == directions.front().first) {
            char newDirection = directions.front().second;
            directions.pop();
            if(newDirection == 'L') currentDir = (currentDir + 4 - 1) % 4; //3
            else if(newDirection ==  'D') currentDir = (currentDir + 1) % 4;
        }
    }
    
    return time;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

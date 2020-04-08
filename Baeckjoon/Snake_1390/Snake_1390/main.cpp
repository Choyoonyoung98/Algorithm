//
//  main.cpp
//  Snake_1390
//
//  Created by 조윤영 on 08/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/3190
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_SIZE 101

using namespace std;

int room[MAX_SIZE][MAX_SIZE];
int N = 0;
int K = 0;
int L = 0;

struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{0,1},{1,0},{0,-1}}; //상 우 하 좌

queue<pair<int,char>> directions;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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

bool isAvailable(int y, int x) {
    if(0<=y && y<N && 0<=x && x<N)return true;
    
    return false;
}
void solution() {
    int cnt = 0;
    queue<pair<int,int>> q;
    
    int currentY = 0;
    int currentX = 0;
    int currentDir = 1;
    room[currentY][currentX] = 2;
    q.push({currentY, currentX});
    
    while(true) {
        
        //방향 전환의 시간이 왔다면
        int changeTime = directions.front().first;
        char changeDir = directions.front().second;
        
        if(cnt == changeTime) {
            
            directions.pop();
            if(changeDir == 'D') {//오른쪽으로
                currentDir = (currentDir+1)%4;
            }else if(changeDir == 'L') {//왼쪽으로
                if(currentDir == 0) {
                    currentDir = 3;
                }else{
                    currentDir = currentDir-1;
                }
            }

        }
        
        
        int nextY = currentY + moveDir[currentDir].y;
        int nextX = currentX + moveDir[currentDir].x;
        
        if(isAvailable(nextY, nextX)) {
            
            //사과가 있다면
            if(room[nextY][nextX] == 1) {
                
            }else if(room[nextY][nextX] == 0){
                //사과가 없다면
                
                int popY = q.front().first;
                int popX = q.front().second;
                room[popY][popX] = 0;
                q.pop();
            }else if(room[nextY][nextX] == 2) {
                //본인의 몸에 부딪히므로 게임 끝
                break;
            }
            
            q.push({nextY, nextX});
            room[nextY][nextX] = 2;
            
            currentY = nextY;
            currentX = nextX;
            cnt++;
        }else{
            //벽에 부딪히므로 게임 끝
            break;
        }

        
    }
    
    cout<<cnt+1<<"\n";
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}

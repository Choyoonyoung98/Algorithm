//
//  main.cpp
//
//
//  Created by 조윤영 on 2020/08/21.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 10
#define MAX_WALL 3
using namespace std;

int N = 0;
int M = 0;
int visited[MAX_SIZE][MAX_SIZE];
int room[MAX_SIZE][MAX_SIZE];
int temp_room[MAX_SIZE][MAX_SIZE];
int maxSafeArea = 0;
queue<pair<int,int>> virus;
int zeroCnt =  0;

struct Dir {
    int y;
    int x;
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
void  input() {
    cin>> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)  {
            cin>> room[i][j];
            if(room[i][j] == 2) {
                virus.push({i, j});
            }else if(room[i][j] == 0) zeroCnt++;
        }
    }
}
bool isAvailable(int y, int x) {
    if(0<= y && y<N &&  0<= x && x<M) {
        if(temp_room[y][x] == 0) return true;
    }
    return false;
}
queue<pair<int,int>> temp_virus;
int spreadVirus() {
    int safeArea = zeroCnt;
    while(!temp_virus.empty())  {
        int virusY = temp_virus.front().first;
        int  virusX = temp_virus.front().second;
        temp_virus.pop();
        
        for(int i=0; i<4; i++) {
            int nextY = virusY + moveDir[i].y;
            int nextX = virusX + moveDir[i].x;
            
            if(isAvailable(nextY, nextX)) {
                temp_room[nextY][nextX] = 2;
                temp_virus.push({nextY, nextX});
                safeArea--;
            }
        }
    }
    return safeArea;
}

void installWall(int cnt) {
    
    if(cnt ==  MAX_WALL)  {
        memcpy(temp_room, room, sizeof(room));
        temp_virus = virus;
        maxSafeArea = max(maxSafeArea, spreadVirus());
        return;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M;  j++)  {
            if(room[i][j] == 0) {
                room[i][j] = 3; //벽 설치
                installWall(cnt+1);
                room[i][j] = 0;
            }
        }
    }
}

void solution() {
    installWall(0);
    cout<<maxSafeArea-3<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();

    solution();
    return 0;
}

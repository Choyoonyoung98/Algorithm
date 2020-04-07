//
//  main.cpp
//  RobotVacuum_14503
//
//  Created by 조윤영 on 06/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//
//https://www.acmicpc.net/problem/14503

#include <iostream>
#define MAX_SIZE 51

using namespace std;

int N = 0;
int M = 0;
int room[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int robotY = 0;
int robotX = 0;
int robotDir = 0;

int answer = 0;

struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{0,1},{1,0},{0,-1}};//북 동 남 서

void input() {
    
    cin>> N >> M;
    cin>>robotY>>robotX>>robotDir;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>room[i][j];
        }
    }
}

bool isAvailable(int y, int x) {
    if(0<=y && y<N && 0<=x && x < M && room[y][x] == 0)return true;
    return false;
}

void dfs(int y, int x, int dir, int searchCnt) {

    
    if(searchCnt == 4) {
        int backY = y + moveDir[(dir+2)%4].y;
        int backX = x + moveDir[(dir+2)%4].x;
        
        //네 방향 모두 청소가 이미 되어있거나 벽인 경우에는
        if(isAvailable(backY, backX)) {
            //바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            dfs(backY, backX, dir, 0);
        }else{//네 방향 모두 청소가 이미 되어있거나 벽이면서,
            //뒤쪽 방향이 벽이라 후진도 할 수 없는 경우
            return;
            
        }
        
    }else{
        if(visited[y][x] !=true){
            visited[y][x] = true;
            answer++;
        }
        
        int nextDir = (dir +3)%4;
        int nextY = y + moveDir[nextDir].y;
        int nextX = x + moveDir[nextDir].x;
        
        //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면
        if(isAvailable(nextY, nextX) && !visited[nextY][nextX] ) {
            //그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
            dfs(nextY, nextX, nextDir,0);
        }
        else if(!isAvailable(nextY, nextX) || visited[nextY][nextX]) {
            //왼쪽 방향에 청소할 공간이 없다면
            //그 방향으로 회전하고 2번으로 돌아간다.
            dfs(y, x, nextDir, searchCnt+1);
        }
    }
    
    

}
void solution() {
    dfs(robotY, robotX, robotDir, 0);
    cout<<answer<<"\n";
}
int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}

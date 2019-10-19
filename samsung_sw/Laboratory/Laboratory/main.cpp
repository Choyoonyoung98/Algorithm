//
//  main.cpp
//  Laboratory
//
//  Created by 조윤영 on 15/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
const int MAX_SIZE = 8;
int N, M;
int wall = 3;
int EmptyCnt = 0;
int room[MAX_SIZE][MAX_SIZE];
int cpy_room[MAX_SIZE][MAX_SIZE] = { 0, };
int safeRoom = 0;

typedef struct {
    int y;
    int x;
}Dir;

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}}; //상, 하, 좌, 우
queue<pair<int,int>> q_virus;

void BFS(int& EmptyCnt) {
    //3개의 벽을 이미 세운 상황
    int afterWall[MAX_SIZE][MAX_SIZE];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            afterWall[i][j] = cpy_room[i][j];
        }
    }
    int zC = EmptyCnt;
    queue<pair<int,int>> Q = q_virus;
    
    while(!Q.empty()) {
        int Virust_y= Q.front().first;
        int Virus_x = Q.front().second;
        Q.pop();
        
        for(int i=0; i<4; i++) {
            int nextY = Virust_y+moveDir[i].y;
            int nextX =Virus_x+moveDir[i].x;
            
            if(0<=nextX&&nextX<=M&&0<=nextY&&nextY<=N && afterWall[nextY][nextX] == 0) {
                afterWall[nextY][nextX] = 2;//세균이 퍼진다.
                zC--; //청정지역이 줄어든다.
                Q.push({nextY,nextX});//퍼진 위치도 바이러스의 위치로 추가
            }
        }
    }
    safeRoom = max(safeRoom, zC); //이거 또 왜 비교하는지 잘 모르겠음 다시 이해 필요
    
}


//cnt = 1(벽의 갯수),zero = 현재 0의 갯수
void makeWall(int cnt, int& zero) {
    
    //cnt = 3(벽의 갯수),zero = 현재 0의 갯수
    if(cnt == 3) {
        BFS(EmptyCnt);
        return;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(cpy_room[i][j] == 0) {//비어 있으면,
                
                cpy_room[i][j] = 1; // 0--->1 //벽을 또 세워?
                EmptyCnt--;
                
                //cnt = 2(벽의 갯수),zero = 현재 0의 갯수
                //cnt = 3(벽의 갯수),zero = 현재 0의 갯수
                makeWall(cnt+1, EmptyCnt);
                
                //3
                //2
                //1
                cpy_room[i][j] = 0;
                zero++;

            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    //**입출력 최적화
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    //세어나갈 갯수를 최대로 두고, 줄여나가자.
    EmptyCnt = N*M; //0의 갯수, 즉 바이러스나 벽이 없는 공간의 갯수
    
    
    int p;
    
    //**주목적: 바이러스, 벽도 아닌 청정 공간 갯수 판단하기
    //즉, 바이러스나 벽을 만나면 청정 공간의 총 갯수를 줄여나가야함.
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            
            cin>>room[i][j];//룸에 대한 정보를 입력받고,
            
            p=room[i][j];//현재 판단하고자 하는 룸의 위치
            
            //입력받는 for문 안에서 바로 판단해버리기. for문 한번 더 돌리면 비효율적이잖아
            if(p !=0) {//바이러스나 벽이 있는 공간을 찾으면,
                EmptyCnt --;//
                //<바뀌지 않는 위치>, 즉 바이러스의 위치는 큐에 담아둔다.
                //왜? 바이러스를 퍼트리는 원인지를 저장해둬야 나중에 바이러스 퍼트리지
                if(p == 2)
                    q_virus.push({i,j}); //바이러스를 찾으면, 큐에 위치를 넣어버린다.
            }
        }
    }
    //여기까지 한 일: 바이러스의 위치 파악, 현재 청정지역의 총 갯수 파악
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(room[i][j] == 0) {//청정지역을 만나면,
                //즉 바이러스가 퍼질 수 있는 공간을 만나면,
                
                //연구실 상태를 복사한다.
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < M; j++)
                        cpy_room[i][j] = room[i][j];
                
                cpy_room[i][j] = 1; //0 --> 1: 청정지역에 벽을 세워?
                EmptyCnt--;//청정지역은 줄어듬
                makeWall(1, EmptyCnt);//벽 사용 갯수와, 청정지역 갯수를 함수 인자로 보낸다.
                cpy_room[i][j] = 0;
                EmptyCnt++;

            }
        }
    }

    cout<<safeRoom<<"\n";
    
    return 0;
}



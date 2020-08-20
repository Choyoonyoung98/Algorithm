//
//  main.cpp
//  AdultShark
//
//  Created by 조윤영 on 2020/08/04.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/19237
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 21
using namespace std;

struct Dir {
    int y;
    int x;
    
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

struct SharkInfo {
    int index;
    int y;
    int x;
    int direction;
    bool isAlive;
    
    SharkInfo(int _index, int _y, int _x, int _direction, int _isAlive) {
        index = _index;
        y = _y;
        x = _x;
        direction = _direction;
        isAlive = _isAlive;
    };
};

struct SmellInfo {
    int y;
    int x;
    int endTime;
    
    SmellInfo(int _y, int _x, int _endTime) {
        y = _y;
        x = _x;
        endTime = _endTime;
    };
};

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}}; //상 하 좌 우
vector<vector<vector<int>>> sharkDir;

int N = 0;
int M = 0;
int K = 0;
int room[MAX_SIZE][MAX_SIZE];
int smell_room[MAX_SIZE][MAX_SIZE]; // 누구의 냄새인지?, 냄새가 중복될 수도 있으니 중복처리를 해야함
int smell_cnt[MAX_SIZE][MAX_SIZE]; //롤백했을 때 덮어씌워질 수 있으므로

vector<SharkInfo> sharks(4, SharkInfo(0,0,0,0,0));
queue<SmellInfo> smells;

void input() {
    cin>> N>> M>> K;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>room[i][j];
            if(room[i][j] != 0) {
                sharks[room[i][j]-1] = SharkInfo(room[i][j]-1, i, j, 0, true);
            }
        }
    }
    
    for(int i=0; i<M; i++) {
        int currentDirection = 0;
        cin>> currentDirection;
        
        sharks[i].direction = currentDirection-1;
    }

    sharkDir.assign(M, {{}});
    for(int i=0; i<M; i++) {
        sharkDir[i].assign(4, {});
        for(int j=0; j<4; j++) {
            for(int h=0; h<4; h++) {
                char dir;
                cin>>dir;
                sharkDir[i][j].push_back((dir - '0') - 1);
            }
        }
    }
}

bool isInBoundary(int y, int x) {
    if( 0<= y && y< N && 0<= x && x< N) return true;
    return false;
}

int solution() {
    for(int t=0; t<1000; t++) {
        int aliveSharkCnt = 0;
        //1. 냄새 없애기를 이동 전에 할 때의 문제점
        //=> 다른 상어가 냄새가 없다고 판단하여 이동할 수 있음.
        if(!smells.empty()) {
            while(true) {
                int smellStartTime = smells.front().endTime;
                int smellY = smells.front().y;
                int smellX = smells.front().x;
                
                if(smellStartTime == t) {
                    smells.pop();
                    smell_cnt[smellY][smellX]--;
                    if(smell_cnt[smellY][smellX] == 0) {
                        smell_room[smellY][smellX] = 0;
                    }
                } else break;
            }
        }
        //2. 냄새 없애기를 이동 후에 할 때의 문제점
        //=> 예를 들어 롤백했는데 냄새가 없다고 덮어씌울 수 있음.
        //시간이 경과했다면 냄새 없애기
        
        for(int i=0; i<sharks.size(); i++) {
            if(sharks[i].isAlive) {
                aliveSharkCnt++;
                
                int currentY = sharks[i].y;
                int currentX = sharks[i].x;
                int currentDir = sharks[i].direction;
//                cout<<i<<":"<<currentY<<","<<currentX;
                smells.push(SmellInfo(currentY, currentX, t+K));
                smell_room[currentY][currentX] = i+1;
                smell_cnt[currentY][currentX]++;
                
                
                //인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
                bool isNoSmellExist = false;
                for(int d=0; d<4; d++) {
                    int nextY = currentY + moveDir[sharkDir[i][currentDir][d]].y;
                    int nextX = currentX + moveDir[sharkDir[i][currentDir][d]].x;
                    if(isInBoundary(nextY, nextX) && smell_cnt[nextY][nextX] == 0) {
//                        cout<<"=>"<<nextY<<","<<nextX<<smell_room[nextY][nextX]<<endl;
                        isNoSmellExist = true;
                        sharks[i] = SharkInfo(i, nextY, nextX, sharkDir[i][currentDir][d], true);
                        
                        room[currentY][currentX] = 0;
                        if(room[nextY][nextX] != 0 && room[nextY][nextX]-1 < i ) {
                            //이미 이동한 상어가 있다면? 충돌!
//                            cout<<"충돌!"<<endl;
                            sharks[i] = SharkInfo(0,0,0,0, false); //격자 밖으로 쫓겨난다.
                            
                        } else room[nextY][nextX] = i+1;
                        
                        break;
                    }
                }
                
//                int rollbackY = -1;
//                int rollbackX = -1;
                
                //그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다
                if(!isNoSmellExist) {
//                    cout<<"이동할 칸이 없다. 롤백 필요";
                    for(int d=0; d<4; d++) {
                        int nextY = currentY + moveDir[sharkDir[i][currentDir][d]].y;
                        int nextX = currentX + moveDir[sharkDir[i][currentDir][d]].x;
                        if(isInBoundary(nextY, nextX) && smell_room[nextY][nextX] == i+1) {
//                            cout<<"=>"<<nextY<<","<<nextX<<endl;
                            sharks[i] = SharkInfo(i, nextY, nextX, sharkDir[i][currentDir][d], true);
                            
                            room[currentY][currentX] = 0;
                            if(room[nextY][nextX] != 0 && room[nextY][nextX]-1 < i ) {
                                //이미 이동한 상어가 있다면? 충돌!
//                                cout<<"충돌"<<endl;
                                sharks[i] = SharkInfo(0,0,0,0, false); //격자 밖으로 쫓겨난다.
                                
                            } else room[nextY][nextX] = i+1;
                            break;
                        }
                    }
                }
            }
        }
//        cout<<"-------------------"<<endl;
        
        if(aliveSharkCnt == 1) return t;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}

//테스트케이스 2번째: 12-> 13

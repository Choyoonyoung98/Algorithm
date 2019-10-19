//
//  main.cpp
//  CleaningMachine
//
//  Created by 조윤영 on 17/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define MAX_SIZE 51

using namespace std;

int room[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
pair<int,int> pos;

typedef struct{
    int y;
    int x;
}Dir;


Dir moveDir[4] = {{-1,0},{0,-1},{1,0},{0,1}};

int N,M;
int r,c,d;
int cnt = 1;
bool moving = true;

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    cin >> r >> c >> d;
    
    pos.first = r;
    pos.second = c;

    
    for(int n=0; n<N; n++) {
        for(int m=0; m<M; m++) {
            cin >> room[n][m];
        }
    }

    int nextX, nextY;
    while(moving == true){

        for(int i=0; i<4; i++) {
            nextY = pos.first+moveDir[(d+1)%4].y;
            nextX = pos.second+moveDir[(d+1)%4].x;

            
            if(room[nextY][nextX] == 0&&visit[nextY][nextX] == false) {//청소를 안했다면,
                cout<<"["<<nextY<<","<< nextX<<"]";
                cout<<cnt<<endl;
                pos = {nextY,nextX};
                d=(d+1)%4;
                visit[nextY][nextX] = true;//청소하기
                cnt++;
                break;
            }else{
                d=(d+1)%4;
            }
            
            
            int backY = pos.first+moveDir[(d+2)%4].y;
            int backX =pos.second+moveDir[(d+2)%4].x;
            
            
            if(i==3 &&room[backY][backX]!=1){
                pos = {backY,backX};
            }else if(i==3 && room[backY][backX]==1) {

                moving = false;
                cout<<cnt;
                break;
            }
            
        }
    }


   
    
    return 0;
}

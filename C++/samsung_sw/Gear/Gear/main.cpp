//
//  main.cpp
//  Gear
//
//  Created by 조윤영 on 08/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX_SIZE 100
#define FOWARD 0
#define BACKWARD 1

#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE -1

using namespace std;
vector<vector<int>> rotation;
int K = 0;
int room[4][8];
int gearNumb = 0;
int rotationDirection = 0;
int direction = 0;
int answer = 0;


void dfs(int gearNumb, int touchState, int searchDirection, int prevRotationDirection) {
    
    if(direction == FOWARD) {
        if(room[gearNumb][2] == touchState)return;
    }
    else {
        if(room[gearNumb][6] == touchState)return;
    }
    
    for(int i=0; i<8; i++) {
        //여기 시계방향 반시계방향 해야함
        if(rotationDirection == CLOCK_WISE){
            if(i-1 >=0){
                room[gearNumb][i]=room[gearNumb][(i-1)%8];
            }else{
                room[gearNumb][i] = room[gearNumb][7];
            }
            
        }else{//COUNTER_CLOCK_WISE
            room[gearNumb][i]=room[gearNumb][(i+1)%8];
        }
        
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            cout<<"["<<room[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<"******************"<<endl;
    if(gearNumb>0){
        touchState = room[gearNumb][6];
        dfs(gearNumb-1, touchState, FOWARD, rotationDirection);
    }
    
    if(gearNumb < 4){
        touchState = room[gearNumb][2];
        dfs(gearNumb+1, touchState, BACKWARD, rotationDirection);
    }
    
    if(gearNumb == 0 || gearNumb == 4)return;
    
    
}
int solution() {
    for(int i=0; i<rotation.size(); i++) {
        cout<<"%%%%"<<i<<"%%%%%"<<endl;
        
        gearNumb = rotation[i][0];
        rotationDirection = rotation[i][1];
        cout<<"gearNumb:"<<gearNumb;
        cout<<"rotationDirection:"<<rotationDirection<<endl;
        
        int touchState = 0;
        
        
        for(int i=0; i<8; i++) {
            //여기 시계방향 반시계방향 해야함
            if(rotationDirection == CLOCK_WISE){
                
                //room[gearNumb][(i-1)]-> 이거 왜 값이 제대로 안찍힐까?
                cout<<room[gearNumb][i]<<","<<room[gearNumb][(i-1)];
                if((i-1)>=0){
                    int prevState = room[gearNumb][(i-1)];
                    cout<<"<"<<i<<">";
                    cout<<prevState<<endl;
                    room[gearNumb][i] = prevState;
                }else{
                    cout<<"<"<<i<<">";
                    cout<<room[gearNumb][7]<<endl;
                    room[gearNumb][i] = room[gearNumb][7];
                }
            }else{//COUNTER_CLOCK_WISE
                cout<<"들어온거 확인";cout<<room[gearNumb][(i+1)%8]<<endl;
                room[gearNumb][i]=room[gearNumb][(i+1)%8];
            }
        }
        
        for(int i=0; i<4; i++) {
            for(int j=0; j<8; j++) {
                cout<<"["<<room[i][j]<<"]";
            }
            cout<<endl;
        }
        cout<<"******************"<<endl;
                  
        if(gearNumb>0){
            touchState = room[gearNumb][6];
            dfs(gearNumb-1, touchState, FOWARD, rotationDirection);
            
        }
                  
        if(gearNumb < 4){
            touchState = room[gearNumb][2];
            dfs(gearNumb+1, touchState, BACKWARD, rotationDirection);
        }
    }
    
    answer = room[0][0]*1 + room[1][0]*2 + room[2][0]*4 + room[3][0]*8;
    return answer;
    
}
int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            cin>>room[i][j];
        }
    }
    
    cin>>K;

    for(int i=0; i<K; i++) {
        cin>> gearNumb;
        cin>> rotationDirection;
        rotation.push_back({gearNumb-1, rotationDirection});
    }
    
    solution();
    
    cout<<"["<<answer<<"]";
    return 0;
}

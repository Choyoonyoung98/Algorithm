//
//  main.cpp
//  CompetitiveTransmission
//
//  Created by 조윤영 on 2020/08/21.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX_SIZE 200
using namespace std;
struct Dir {
    int y;
    int x;
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
int room[MAX_SIZE][MAX_SIZE];
struct Virus {
    int type;
    int y;
    int x;
    Virus(int _type, int _y, int _x) {
        type = _type;
        y = _y;
        x = _x;
    };
};
priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
int N = 0;
int K = 0;
int S = 0;
int X = 0;
int Y = 0;
void input() {
    cin>> N >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>room[i][j];
            if(room[i][j] != 0) {
                q.push({room[i][j], {i, j}});
            }
        }
    }
    
    cin>> S >> X >> Y;
}

bool isAvailable(int y, int x) {
    if(0<= y && y< N && 0<= x && x< N) return true;
    return false;
}

void  solution() {
    for(int i=0; i<S; i++) {
        int qSize = q.size();
        queue<Virus> temp_q;
        for(int j=0; j<qSize; j++) {
            int type = q.top().first;
            int y = q.top().second.first;
            int x = q.top().second.second;
            q.pop();
            for(int d=0; d<4; d++)  {
                int nextY = y + moveDir[d].y;
                int nextX = x + moveDir[d].x;
                
                if(isAvailable(nextY, nextX) && room[nextY][nextX] == 0) {
                    room[nextY][nextX] = type;
                    temp_q.push(Virus(type, nextY, nextX));
                }
            }
        }
        while(!temp_q.empty()) {
            int type = temp_q.front().type;
            int y = temp_q.front().y;
            int x = temp_q.front().x;
            q.push({type, {y, x}});
            temp_q.pop();
        }
    }
    
    cout<<room[X-1][Y-1]<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

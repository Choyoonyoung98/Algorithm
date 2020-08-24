//
//  main.cpp
//  PopulationMovement
//
//  Created by 조윤영 on 2020/08/23.
//  Copyright © 2020 조윤영. All rights reserved.
//
//이거 통과 안함

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX_SIZE 51
using namespace std;

int N = 0;
int L = 0;
int R = 0;
int room[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
queue<pair<int,int>> unions;
int unionsSum = 0;

struct Dir {
    int y;
    int  x;
};
Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void input() {
    cin>> N >> L  >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>> room[i][j];
        }
    }
}
int temp_visited[MAX_SIZE][MAX_SIZE];

bool checkAvailable(int y, int x) {
    if(0<= y && y < N && 0<= x && x < N) return true;
    return false;
}

bool checkIsUnion(int aY,  int aX, int bX, int bY) {
    int differ = abs(room[aY][aX] - room[bY][bX]);
    if(L<= differ && differ <= R) return true;
    return false;
}

bool makeMovement() {
    int unionCnt = unions.size();
    int averageUnionValue =  unionsSum / unionCnt;
    if(unionCnt == 1) return false;

    while(!unions.empty()) {
        int y = unions.front().first;
        int x = unions.front().second;
        unions.pop();
        
        room[y][x] =  averageUnionValue;
    }
    return true;
}

int findUnion(int y, int x) {
    int unionCnt = 0;
    queue<pair<int,int>> q;
    unionsSum += room[y][x];
    unions.push({y,x});
    q.push({y,x});
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        unionCnt++;
        for(int i=0; i<4; i++) {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            if(checkAvailable(nextY, nextX) && !temp_visited[nextY][nextX]) {
                if(checkIsUnion(y, x, nextY, nextX)) {
                    temp_visited[nextY][nextX] = true;
                    q.push({nextY, nextX});
                    
                    unionsSum += room[nextY][nextX];
                    unions.push({nextY,nextX});
                }
            }
        }
    }
    return unionCnt;
}

bool checkUnion() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!temp_visited[i][j])  {
                temp_visited[i][j] = true;
                if(findUnion(i, j) == 1) {
                    unionsSum = 0;
                    unions.pop();
                    continue;
                }
                else return true;
            }
        }
    }
    return false;
}

int solution() {
    int answer = 0;
    while(true) {
        memcpy(temp_visited, visited, sizeof(visited));
        if(!checkUnion()) return answer;
        else {
            makeMovement();
            answer++;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

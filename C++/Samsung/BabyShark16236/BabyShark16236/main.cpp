//
//  main.cpp
//  BabyShark16236
//
//  Created by 조윤영 on 2021/03/25.
//
#define MAX_SIZE 21
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int room[MAX_SIZE][MAX_SIZE];
int N;
int startY, startX;

struct Pos {
    int y;
    int x;
    int dist;
    Pos(int _y, int _x, int _dist) {
        y = _y;
        x = _x;
        dist = _dist;
    };
    Pos(int _y, int _x) {
        y = _y;
        x = _x;
        dist = 0;
    };
};

Pos moveDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[MAX_SIZE][MAX_SIZE];

//비교함수 구현 중요중요!
//작은 것부터 정렬하려면 >
//큰 것부터 정렬하려면 <
bool operator < (Pos a, Pos b) {
    if(a.dist == b.dist) {
        if(a.y == b.y) return a.x > b.x;
        return a.y > b.y;
    }
    return a.dist > b.dist;
}

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++ ) {
            cin>> room[i][j];
            if(room[i][j] == 9) {
                startY = i;
                startX = j;
            }
        }
    }
}

bool isAvailable(int y, int x) {
    if(0<= y && y < N && 0<= x && x < N) return true;
    return false;
}

int solution() {
    int answer = 0;
    queue<Pos> q;
    int size = 2;
    int cnt = 0;
    
    q.push(Pos(startY, startX));
    visited[startY][startX] = true;
    room[startY][startX] = 0;
    //점차 아기상어의 몸집을 키우면서 탐색 진행
    while(true) {
        priority_queue<Pos> pq;
        while(!q.empty()) {
            int currentY = q.front().y;
            int currentX = q.front().x;
            int currentDist = q.front().dist;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int nextY = currentY + moveDir[i].y;
                int nextX = currentX + moveDir[i].x;
                if(isAvailable(nextY, nextX) && !visited[nextY][nextX] && room[nextY][nextX] <= size) {
                    if(room[nextY][nextX] != 0 && room[nextY][nextX] < size) {//작은 물고기 맞음
                        pq.push(Pos(nextY, nextX, currentDist+1));
                    }
                    visited[nextY][nextX] = true;
                    q.push(Pos(nextY, nextX, currentDist+1));
                }
            }
        }

        if(!pq.empty()) {
            int fishY = pq.top().y;
            int fishX = pq.top().x;
            int fishDist = pq.top().dist;
            room[fishY][fishX] = 0;
            answer = fishDist;
            q.push(Pos(fishY, fishX, fishDist));
        } else return answer;
        memset(visited, false, sizeof(visited));

        if(++cnt == size) {
            cnt = 0;
            size++;
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

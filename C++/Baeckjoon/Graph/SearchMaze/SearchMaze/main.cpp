//
//  main.cpp
//  SearchMaze
//
//  Created by 조윤영 on 2020/11/23.
//
//미로 탐색
//그래프 BFS를 통한 최단 거리 탐색. visited check를 어느 시점에 해야 효율적인지를 잘 생각해보자
//https://www.acmicpc.net/problem/2178

#define MAX_SIZE 101
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N, M;
int room[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char temp;
            cin>> temp;
            room[i][j] = temp - '0';
        }
    }
}

struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
Dir moveDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Pos {
    int y;
    int x;
    int cnt;
    Pos(int _y, int _x, int _cnt) {
        y = _y;
        x = _x;
        cnt = _cnt;
    };
};

bool isAvailable(int y, int x) {
    if(0<= y && y < N && 0<= x && x < M) return true;
    return false;
}

int solution() {
    queue<Pos> q;
    q.push(Pos(0,0,1));
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        
        if( y == N-1 && x == M-1) return cnt;
        
        for(int d = 0; d < 4; d++) {
            int nextY = y + moveDir[d].y;
            int nextX = x + moveDir[d].x;
            
            if(isAvailable(nextY, nextX) && !visited[nextY][nextX] && room[nextY][nextX] == 1) {
                visited[nextY][nextX] = true;
                q.push(Pos(nextY, nextX, cnt+1));
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    input();
    cout<<solution()<<"\n";
    
    return 0;
}

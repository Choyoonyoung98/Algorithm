//
//  main.cpp
//  NumberingEstate_2667
//
//  Created by 조윤영 on 2020/11/23.
//https://www.acmicpc.net/problem/2667
// 데이터가 0일 때, 1일 때, 최대 갯수일 때 발생되는 예외에 대해서 생각하면서 문제를 풀어보자
//단지 번호 붙이기


#define MAX_SIZE 26
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N = 0;
int room[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void input() {
    cin>> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char x;
            cin>> x;
            room[i][j] = x - '0';
         }
    }
}

struct Pos {
    int y;
    int x;
    Pos(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

Pos moveDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isAvailble(int y, int x) {
    if(0<= y && y <N && 0<= x && x < N) return true;
    return false;
}

int BFS(int y, int x) {
    int result = 0;
    queue<Pos> q;
    q.push(Pos(y, x));
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for(int d = 0; d< 4; d++) {
            int nextY = y + moveDir[d].y;
            int nextX = x + moveDir[d].x;
            if(!visited[nextY][nextX] && isAvailble(nextY, nextX) && room[nextY][nextX] == 1) {
                visited[nextY][nextX] = true;
                result ++;
                q.push(Pos(nextY, nextX));
            }
        }
    }
    if(result == 0) return 1;
    return result;
}

void solution() {
    vector<int> answer;
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(room[i][j] == 1 && !visited[i][j]) {
                cnt++;
                answer.push_back(BFS(i, j));
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout<<cnt<<"\n";
    for(int a: answer) cout<<a<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

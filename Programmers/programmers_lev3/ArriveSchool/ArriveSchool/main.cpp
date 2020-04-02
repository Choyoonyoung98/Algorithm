//
//  main.cpp
//  ArriveSchool
//
//  Created by 조윤영 on 06/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 101
using namespace std;

int room[MAX_SIZE][MAX_SIZE]= {0};
int puddle[MAX_SIZE][MAX_SIZE];

//DP 풀이
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //puddle 설치하기
    for(int i=0; i<puddles.size();i++) {
        int puddleY = puddles[i][1];
        int puddleX = puddles[i][0];
    
        puddle[puddleY][puddleX] = -1;
    }
    
    room[1][0] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(puddle[i][j] == -1) room[i][j] = 0;
            else room[i][j] = (room[i-1][j]+room[i][j-1]) % 1000000007;
        }
    }
    
    answer = room[n][m];
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> puddles = {{2,2}};
    cout<<solution(4, 3, puddles);
    return 0;
}


//BFS로 풀었다가 실패한 풀이.. 이유는 아직 모르겠음.
//
//bool visited[MAX_SIZE][MAX_SIZE];
//
//
//struct Dir {
//    int y;
//    int x;
//};
//
//struct Way {
//    int y;
//    int x;
//    int cnt;
//};
//
//Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
//
//
//
//bool inBoundary(int n, int m, int y, int x) {
//
//    if(0<=y && y<n && 0<=x && x<m)  {
//        if (room[y][x]!=1 && visited[y][x] != true) return true;
//    }
//
//    return false;
//}
//
//int solution(int m, int n, vector<vector<int>> puddles) {
//    int answer = MAX_SIZE;
//
//    queue<Way> q;
//
//    q.push({0,0,-1});
//    visited[0][0] = true;
//
//    //puddle 설치하기
//    for(int i=0; i<puddles.size();i++) {
//        int puddleY = puddles[i][1]-1;
//        int puddleX = puddles[i][0]-1;
//
//        room[puddleY][puddleX] = 1;
//    }
//
//    while(!q.empty()) {
//        int currentY = q.front().y;
//        int currentX = q.front().x;
//        int cnt = q.front().cnt;
//
//        cout<<currentY<<","<<currentX<<endl;
//        q.pop();
//
//        if(currentY == n-1 && currentX == m-1){
//            cout<<"cnt:"<<cnt<<endl;
//            answer = min(cnt, answer);
//        }
//        else {
//            for(int i=0; i<4; i++) {
//                int nextY = currentY + moveDir[i].y;
//                int nextX = currentX + moveDir[i].x;
//
//                if(inBoundary(n, m, nextY, nextX)) {
//                    visited[nextY][nextX] = true;
//                    int nextCnt = (cnt+1)%1000000007;
//                    q.push({nextY, nextX, nextCnt});
//                }
//            }
//        }
//
//
//    }
//
//    return answer;
//}

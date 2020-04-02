//
//  main.cpp
//  NQueen
//
//  Created by 조윤영 on 26/02/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <stack>
#define MAX_SIZE 13
using namespace std;

int result = 0;
int col[MAX_SIZE];

bool check(int i) {
    for(int j=0; j<i; j++) {
        
        //새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        //대각선에 있을 경우: x1-x2 == y1-y2
        if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))return false;
    }
    return true;
}
void dfs(int index, int n) {
    if(index == n)result +=1;
    else {
        for(int i=0; i<n; i++) {
            col[index] = i; //i번째 줄에는 퀸이 j에 위치하고 있음
            if(check(index)) dfs(index+1, n);
        }
    }
}
int solution(int n) {
    int answer = 0;
    
    dfs(0, n);
    answer = result;
    
    return answer;
    
}
int main(int argc, const char * argv[]) {
    int n = 4;
    
    solution(n);
    return 0;
}

//어렵게 생각했다 망한 나의 풀이 (정답률은 괜찮은데 시간초과 남)
//int visited[MAX_SIZE][MAX_SIZE];
//int cnt = 0;
//stack<pair<int,int>> temp;
//
//struct Dir {
//    int y;
//    int x;
//
//};
//
//int room[MAX_SIZE][MAX_SIZE];
//
//Dir moveDir[8] = {{-1,0},{1,0},{0,-1},{0,1}, {-1,-1}, {1,1},{-1,1},{1,-1}};
//
//bool isAvailable(int y, int x, int n) {
//    if(0<=y && y<n && 0<=x && x <n && visited[y][x]!=true)return true;
//    return false;
//}
//
//bool isAvailable2(int y, int x, int n) {
//    if(0<=y && y<n && 0<=x && x <n && visited[y][x]!=false)return true;
//    return false;
//}
//
//void dfs(int index, int n, int queenCnt) {
//
//
//    if(queenCnt == n){
//        cnt++;
//        return;
//    }
//
//    for(int i=0; i<n; i++) {
//
//        if(visited[index][i] != true) {
//
//            int currentY = index;
//            int currentX = i;
//            int nextY = 0;
//            int nextX = 0;
//
//            int plusY = 0;
//            int plusX = 0;
//
//            visited[index][i] = true;
//
//            for(int j=0; j<8; j++) {
//                plusY = moveDir[j].y;
//                plusX = moveDir[j].x;
//                nextY = currentY + plusY;
//                nextX = currentX + plusX;
//
//                while(0<=nextY && nextY <n && 0<=nextX && nextX <n) {
//
//                    nextY = currentY + plusY;
//                    nextX = currentX + plusX;
//
//                    if(isAvailable(nextY, nextX, n)){
//                        temp.push({nextY, nextX});
//                        visited[nextY][nextX] = true;
//                    }
//
//                    plusY *= 2;
//                    plusX *= 2;
//                }
//
//            }
//
//            dfs(index+1, n, queenCnt+1);
//
//            visited[index][i] = false;
//
//            while(!temp.empty()) {
//                int visitedY = temp.top().first;
//                int visitedX = temp.top().second;
//
//                visited[visitedY][visitedX] = false;
//                temp.pop();
//            }
//        }
//    }
//}
//
//int solution(int n) {
//    int answer = 0;
//
//    dfs(0, n, 0);
//    answer = cnt;
//    return answer;
//}

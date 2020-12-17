//
//  main.cpp
//  GoldMine
//
//  Created by 조윤영 on 2020/08/28.
//  Copyright © 2020 조윤영. All rights reserved.
//
//금광
//

#include <iostream>
#include <queue>
#define MAX_SIZE 21
using namespace std;
int solution();
int solution2();

int T = 0;
int n = 0;
int m = 0;
int room[MAX_SIZE][MAX_SIZE];

struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
Dir moveDir[3] = {{0,1},{-1,1},{1,1}};//오른쪽, 오른쪽 위, 오른쪽 아래

void input() {
    cin>>T;
    for(int t=0; t<T; t++) {
        cin>> n>> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>> room[i][j];
            }
        }
        cout<<solution2()<<"\n";
    }
}

bool isAvailable(int y, int x) {
    if(0<= y && y<n && 0<= x && x<m) return true;
    return false;
}

struct Mine {
    int y;
    int x;
    int sum;
    Mine(int _y, int _x, int _sum) {
        y = _y;
        x = _x;
        sum = _sum;
    };
};

//Dynamic Programming
//dp[i][j] = array[i][j] + max(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]) //왼쪽 위, 왼쪽, 왼쪽 위
int solution2() {
    int answer = 0;
    
    int dp[MAX_SIZE][MAX_SIZE];
    int index = 0;
    
    //다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = room[i][j];
        }
    }
    
    for(int j=1; j<m; j++) {
        for(int i=0; i<n; i++) {
            int leftUp, leftDown, left;
            //인덱스 1번째 줄부터 시작
            
            //1. 왼쪽 위에서 오는 경우
            if(i==0) leftUp = 0; //0번째 행은 왼쪽 위에서 올 수 없기 때문에 0
            else leftUp = dp[i-1][j-1]; //나머지 1번째 행부터는 왼쪽 위에서 올 수 있는 왼쪽 위 인덱스들이 존재.
            
            //왼쪽 아래에서 오는 경우
            if(i == n-1) leftDown = 0;//맨 아래 행의 경우에는 왼쪽 아래에서 오는 경우가 없으므로 0
            else leftDown = dp[i+1][j-1];
            
            //왼족에서 오는 경우
            left = dp[i][j-1];
            dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
        }
    }

    for(int i=0; i<n; i++) answer = max(answer, dp[i][m-1]);
    return answer;
}

//BFS
int solution() {
    int answer = 0;
    queue<Mine> q;

    for(int i=0; i<n; i++) q.push(Mine(i,0,room[i][0]));
    while(!q.empty()) {
        
        int y = q.front().y;
        int x = q.front().x;
        int sum = q.front().sum;
        q.pop();
        
        if(x == m-1) {
            answer = max(answer, sum);
            continue;
        }
        
        for(int d = 0; d<3; d++) {
            int nextY = y + moveDir[d].y;
            int nextX = x + moveDir[d].x;
            
            if(isAvailable(nextY, nextX)) q.push(Mine(nextY, nextX, sum+room[nextY][nextX]));
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}

/*
 2
 3 4
 1 3 3 2 2 1 4 1 0 6 4 7
 4 4
 1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
 
 
 1
 3 4
 1 3 3 2 2 1 4 1 0 6 4 7
 */

//
//  main.cpp
//  IntegerTriangle
//
//  Created by 조윤영 on 2020/08/28.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/1932

#include <iostream>
#define MAX_SIZE 501
using namespace std;

int n = 0;
int dp[MAX_SIZE][MAX_SIZE];
void input() {
    cin>> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            cin>>dp[i][j];
        }
    }
}

int solution() {
    int answer = 0;
    if(n == 1) return dp[1][0];

    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            int rightUp, leftUp;
            
            //왼쪽 위에서 내려올 경우
            if(j == 0) leftUp = 0;
            else leftUp = dp[i-1][j-1];
            
            //오른쪽 위에서 내려올 경우
            if(j == i-1) rightUp = 0;
            else rightUp = dp[i-1][j];
            
            dp[i][j] += max(leftUp, rightUp);
        }
    }

    for(int i=0; i<n; i++) answer = max(answer, dp[n][i]);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

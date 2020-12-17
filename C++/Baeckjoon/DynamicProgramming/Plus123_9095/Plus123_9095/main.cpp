//
//  main.cpp
//  Plus123_9095
//
//  Created by 조윤영 on 2020/11/27.
//https://www.acmicpc.net/problem/9095
//
//1,2,3 더하기
#define MAX_SIZE 11
#include <iostream>
using namespace std;

int dp[MAX_SIZE];
int T = 0;
int solution(int N);

void input() {
    cin>> T;
    int n = 0;
    for(int t=0; t<T; t++) {
        cin>> n;
        cout<<solution(n)<<"\n";
    }
}

int solution(int N) {
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    
    for(int i=4; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[N];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}

//
//  main.cpp
//  MakeNumber1_1463
//
//  Created by 조윤영 on 2020/11/23.
//
//https://www.acmicpc.net/problem/1463
//Dynamic Programming으로 n가지 경우를 통해 목표 숫자 1 만들기
//1로 만들기

#define INF 1e9
#define MAX_SIZE 1000000
#include <iostream>
#include <queue>
using namespace std;

int N = 0;
void input() {
    cin>> N;
}

//Dynamic Programming(*)
int solution3() {
    int dp[MAX_SIZE];
    
    fill(dp, dp+N+1, INF);
    dp[N] = 0; //dp[N]: 정수 N을 만드는 데 필요한 최소 연산 횟수
    
    //dp[N] 은 dp[N-1], dp[N/3], dp[N/2]에서 한 번의 연산을 더 수행해서 만들 수 있다!
    for(int i=N; i> 0; i--) {
        if(i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
        if(i % 2 == 0) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
    }
    
    return dp[1];
}

//BFS
int solution() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    while(!q.empty()) {
        int X = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(X < 1) continue;
        else if(X == 1) return cnt;
        
        if(X % 3 == 0) q.push({X/3, cnt+1});
        if(X % 2 == 0) q.push({X/2, cnt+1});
        q.push({X-1, cnt+1});
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
//    cout<<solution()<<"\n";
//    cout<<solution2()<<"\n";
    cout<<solution3()<<"\n";
    
    return 0;
}

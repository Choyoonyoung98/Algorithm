//
//  main.cpp
//  Coin_2293
//
//  Created by 조윤영 on 2021/01/22.
//
#define MAX_SIZE 10001
#include <iostream>
#include <vector>
using namespace std;

int N, K = 0;
vector<int> coins;
void input() {
    cin>> N >> K;
    coins.assign(N, 0);
    for(int i=0; i<N; i++) { cin>> coins[i]; }
}

void solution() {
    int dp[MAX_SIZE];
    fill(dp, dp+MAX_SIZE, 0);
    dp[0] = 1;
    for(int coin: coins) {
        for(int i=coin; i<= K; i++) dp[i] += dp[i-coin];
    }
    cout<<dp[K]<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

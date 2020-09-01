//
//  main.cpp
//  DeployingSoldiers
//
//  Created by 조윤영 on 2020/09/01.
//  Copyright © 2020 조윤영. All rights reserved.
//
//LIS(최장 증가 부분 수열 문제)
//https://www.acmicpc.net/problem/18353
//

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_SIZE 2001
using namespace std;
int N = 0;
vector<int> soldiers;
void input() {
    cin>> N;
    soldiers.assign(N, 0);
    for(int i=0; i<N; i++) cin>> soldiers[i];
}

int solution() {
    int maxValue = 0;
    
    //순서를 뒤집어 '최장 증가 부분 수열 문제로 변환
    reverse(soldiers.begin(), soldiers.end()); //오름차순으로 정렬
    int dp[MAX_SIZE];
    //다이나믹 프로그래밍을 위한 1차원 DP 테이블 초기화
    for(int i=0; i<N; i++) dp[i] = 1;
    
    //가장 긴 증가하는 부분 수열 알고리즘 수행(LIS)
    for(int i=1; i<N; i++) {
        for(int j=0; j<i; j++) {
            if(soldiers[j] < soldiers[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=0; i<N; i++) maxValue = max(maxValue, dp[i]);
    return N-maxValue;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

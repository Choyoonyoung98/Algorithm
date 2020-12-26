//
//  main.cpp
//  Quit
//
//  Created by 조윤영 on 2020/08/28.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/14501
//
#include <iostream>
#include <vector>
#define MAX_SIZE 16
using namespace std;

int N = 0;
int dp[MAX_SIZE]; //이익
struct Schedule {
    int t;
    int p;
    
    Schedule(int _t, int _p) {
        t = _t;
        p = _p;
    };
};
vector<Schedule> consulting;

void input() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int T = 0;
        int P = 0;
        cin>> T>>P;
        consulting.push_back(Schedule(T, P));
    }
}

int solution() {
    int maxValue = 0;
    //리스트를 뒤에서부터 거꾸로 확인
    for(int i=N-1; i>= 0; i--) {
        int time = consulting[i].t;
        int pay = consulting[i].p;
        
        if(time + i <= N) {
            dp[i] = max(pay + dp[i+time], maxValue);
            maxValue = dp[i];
        } else dp[i] = maxValue;
        
    }
    
    return maxValue;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

    //dp[6] = 0
    //dp[5] = 0
    /*
     dp[4] = 15 + dp[4+2](0), 0  ->15
     dp[3] = 20 + dp[3+1](15), 15 -> 35
     dp[2] = 10 + dp[2+1](35), 35 // 45
     dp[1] = 10 + dp[1+3](15), 45 //45
*/

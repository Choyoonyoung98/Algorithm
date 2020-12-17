//
//  main.cpp
//  UglyNumber
//
//  Created by 조윤영 on 2020/09/02.
//  Copyright © 2020 조윤영. All rights reserved.
//
//못생긴 수: 2,3,5만을 소인수로 가지는 수를 의미합니다.
//

#include <iostream>
#define MAX_SIZE 1001
using namespace std;
int  N = 0;
void input() {
    cin>> N;
}

int dp[MAX_SIZE];
int solution() {
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3,  next5 = 5;
    
    dp[0] = 1;
    for(int i=1; i<N; i++) {
        dp[i] = min(next2, min(next3, next5));
        
        if(dp[i] == next2){
            i2 += 1;
            next2 = dp[i2] * 2;
        }
        if(dp[i] == next3)  {
            i3 += 1;
            next3 =  dp[i3] * 3;
        }
        if(dp[i] == next5) {
            i5 += 1;
            next5 = dp[i5] * 5;
        }
    }
    
    return dp[N-1];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}

//
//  main.cpp
//  AdventurerGuild
//
//  Created by 조윤영 on 2020/08/07.
//  Copyright © 2020 조윤영. All rights reserved.
//
// 모험가 길드

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N = 0;
vector<int> fears;

void input() {
    cin>> N;
    fears.assign(N, 0);
    
    for(int i=0; i<N; i++) {
        cin>> fears[i];
    }
}

int solution() {
    int answer = 0;
    sort(fears.begin(), fears.end());

    int cnt = 0;
    
    for (int fear: fears) {
        cnt++;
        if(cnt >= fear)  {
            cnt = 0;
            answer++;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    
    return 0;
}

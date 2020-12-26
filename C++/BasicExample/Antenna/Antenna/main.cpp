//
//  main.cpp
//  Antenna
//
//  Created by 조윤영 on 2020/08/24.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/18310
//원리를 알면 신기한 문제!!!!!

#include <algorithm>
#include <iostream>
#include <vector>

using namespace  std;
int N = 0;
vector<int> houses;
void input() {
    cin>> N;
    houses.assign(N, 0);
    for(int i=0; i<N; i++) cin>> houses[i];
}

void solution()  {
    sort(houses.begin(), houses.end());
    cout<<houses[(N-1)/2]<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}

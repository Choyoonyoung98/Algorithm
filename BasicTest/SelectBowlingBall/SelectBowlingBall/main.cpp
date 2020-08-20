//
//  main.cpp
//  SelectBowlingBall
//
//  Created by 조윤영 on 2020/08/09.
//  Copyright © 2020 조윤영. All rights reserved.
//
//볼링공 고르기

#include <iostream>
#include <vector>
#define MAX_SIZE 11

using namespace std;

int N =  0;
int M = 0;
vector<int> weights;
int room[MAX_SIZE];

void input() {
    cin>> N >> M;
    
    weights.assign(N, 0);
    for(int  i=0; i<N; i++) cin>> weights[i];
}

int solution()  {
    int answer = 0;
    
    for (int w: weights) room[w]++;
    
    for(int i=0; i<M; i++) {
        N -= room[i];
        answer += N*room[i];
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

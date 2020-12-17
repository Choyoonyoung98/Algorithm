//
//  main.cpp
//  LuckyStraight
//
//  Created by 조윤영 on 2020/08/11.
//  Copyright © 2020 조윤영. All rights reserved.
//
//럭키 스트레이트

#include <iostream>

using namespace std;

int N;
void input() {
    cin>> N;
}

string solution() {
    string s_N = to_string(N);
    
    int leftSum = 0;
    int rightSum = 0;
    for(int i=0; i<s_N.size(); i++) {
        if(i<s_N.size()/2) leftSum += s_N[i] - '0';
        else rightSum += s_N[i] - '0';
    }
    
    if(leftSum == rightSum) return "LUCKY";
    else return "READY";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}

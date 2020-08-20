//
//  main.cpp
//  MultipleAndPlus
//
//  Created by 조윤영 on 2020/08/08.
//  Copyright © 2020 조윤영. All rights reserved.
//
//그리디 문제: 곱하기 혹은 더하기

#include <iostream>

using namespace std;

string s_numbers;

void input() {
    cin>>s_numbers;
}

void solution() {
    int sum  = 0;
    for(char n: s_numbers){
        sum = (sum * (n - '0') >= sum + (n - '0')) ? sum * (n - '0') : sum + (n - '0');
    }
    cout<<sum<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    return 0;
}


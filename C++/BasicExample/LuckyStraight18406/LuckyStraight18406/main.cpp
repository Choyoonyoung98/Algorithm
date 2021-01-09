//
//  main.cpp
//  LuckyStraight18406
//
//  Created by 조윤영 on 2021/01/09.
//

#include <iostream>
using namespace std;

int N = 0;

void input() {
    cin>> N;
}

string solution() {
    string s_N = to_string(N);
    int leftSum = 0;
    int rightSum = 0;
    for(int i=0; i<s_N.size(); i++) {
        if(i < s_N.size()/2) leftSum += s_N[i] - '0';
        else rightSum += s_N[i] - '0';
    }
    
    if (leftSum == rightSum) return "LUCKY";
    
    return "READY";
}

int main(int argc, const char * argv[]) {
    input();
    cout<<solution()<<"\n";
    return 0;
}

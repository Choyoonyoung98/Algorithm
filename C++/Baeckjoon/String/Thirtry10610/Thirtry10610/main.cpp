//
//  main.cpp
//  Thirtry10610
//
//  Created by 조윤영 on 2021/03/09.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;
void input() {
    cin>> N;
}

bool cmp(char a, char b) {
    if (a > b) return true;
    return false;
}

string solution() {
    long long sum = 0;
    bool zero = false;

    for (int i = 0; i < N.size(); i++) {
        sum += (N[i] - '0');
        if ((N[i]-'0') == 0) zero = true;
    }
    if(sum %3 || !zero) return "-1";
    else sort(N.begin(), N.end(), cmp);
    return N;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

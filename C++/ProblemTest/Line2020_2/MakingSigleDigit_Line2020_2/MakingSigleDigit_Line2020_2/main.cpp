//
//  main.cpp
//  MakingSigleDigit_Line2020_2
//
//  Created by 조윤영 on 2021/02/26.
//
//최적화가 힘들어보이면 완탐이 맞다 의심하지마라
#define INF 1e9
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt = INF;
int result = 0;

void makeSingleDigit(string n, int count) {
    if(count > cnt) return;
    if(n.size() == 1) {
        cnt = count;
        result = stoi(n);
    }
    
    for(int i=1; i<=n.size()-1; i++) {
        string a = n.substr(0, i);
        string b = n.substr(i, n.size()-i);
        if(a[0] == '0') continue;
        else if(b[0] == '0') continue;
        
        int sum = stoi(a) + stoi(b);
        makeSingleDigit(to_string(sum), count+1);
    }
}
vector<int> solution(int n) {
    vector<int> answer;
    string s_n = to_string(n);
    makeSingleDigit(s_n, 0);
    answer.push_back(cnt);
    answer.push_back(result);
    cout<<cnt<<" "<<result<<endl;
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 9;
    solution(n);
    return 0;
}

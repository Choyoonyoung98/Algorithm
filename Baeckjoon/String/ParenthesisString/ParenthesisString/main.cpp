//
//  main.cpp
//  ParenthesisString
//
//  Created by 조윤영 on 2020/11/22.
//
//괄호
//NOTE:
//https://www.acmicpc.net/problem/9012

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int T = 0;
string solution(string parenthesis);
void input() {
    cin>>T;
    for(int i=0; i<T; i++) {
        string parenthesis;
        cin>>parenthesis;
        cout<<solution(parenthesis)<<"\n";
    }
}

string solution(string parenthesis) {
    stack<char> s;
    for(char c: parenthesis) {
        if(c == '(') s.push('(');
        else {
            if(s.empty()) return "NO";
            else s.pop();
        }
    }
    
    if(!s.empty()) return "NO";
    return "YES";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}

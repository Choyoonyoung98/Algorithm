//
//  main.cpp
//  ParenthesisConversion
//
//  Created by 조윤영 on 2020/08/22.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/60058
//
//여기서 중요한 것은 U가 "균형잡힌 괄호 문자열" 이면서 동시에 "올바른 괄호 문자열"로 변환할 수 있는 문자라는 사실을 잊지말 것.
#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool checkCorrectString(string u);
int findBalanceStringIndex(string w);
string makeUCorrectString(string u, string v);
string makeUAndV(string w);

string solution(string p) {
    string answer = "";
    if(p == "") return "";
    answer = makeUAndV(p);
    return answer;
}

string makeUAndV(string w) {
    if(w == "") return "";
    string u;
    string v;
    int seperateIndex = 0;
    seperateIndex = findBalanceStringIndex(w);
    u = w.substr(0,seperateIndex);
    v = w.substr(seperateIndex);
    
    if(!checkCorrectString(u)) u = makeUCorrectString(u, v);
    else u += makeUAndV(v);
    
    return u;
}

string makeUCorrectString(string u, string v) {
    u = u.substr(1,u.size()-2);
    string temp_u = "";
    for(char c: u) {
        if(c == '(') temp_u += ')';
        else temp_u += '(';
    }
    u = temp_u;
    
    u = '(' + makeUAndV(v) + ')' + u;
    return u;
}

int findBalanceStringIndex(string w) {
    int leftCnt = 0;
    int rightCnt = 0;
    int index = 0;
    for(int i=0; i<w.size(); i++) {
        if(i != 0 && leftCnt == rightCnt) return i;

        if(w[i] == '(') leftCnt++;
        else rightCnt++;
    }
    return w.size();
}

bool checkCorrectString(string u) {
    stack<char> s;
    for(char c: u) {
        
        if(c == '(') s.push(c);
        else if(!s.empty() && c == ')')s.pop();
        else return false;
    }
    if(s.empty()) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    string p = "()))((()";
    cout<<solution(p)<<"\n";
    return 0;
}

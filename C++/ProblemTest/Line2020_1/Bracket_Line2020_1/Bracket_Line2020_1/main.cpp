//
//  main.cpp
//  Bracket_Line2020_1
//
//  Created by 조윤영 on 2021/02/26.
//

#include <iostream>
#include <stack>
using namespace std;

char findBracket(char c) {
    switch(c) {
        case ')':
            return'(';
            break;
        case ']':
            return '[';
            break;
        case '}':
            return '{';
            break;
        case '>':
            return '<';
            break;
        default:
            break;
    }
    return '-';
}
int solution(string inputString) {
    int answer = 0;
    stack<char> s;
    
    for(char c: inputString) {
        if(c == '(' || c == '[' || c == '{' || c == '<') s.push(c);
        else if (c == ')' || c == ']' || c == '}'|| c == '>') {
            char bracket = findBracket(c);
            if(s.empty() || s.top() != bracket ) return -1;
            else {
                s.pop();
                answer += 1;
            }
        }
    }
    if(!s.empty()) return -1;
    return answer;
}
int main(int argc, const char * argv[]) {
    string inputString = ">_<";
    cout<<solution(inputString)<<endl;
    return 0;
}

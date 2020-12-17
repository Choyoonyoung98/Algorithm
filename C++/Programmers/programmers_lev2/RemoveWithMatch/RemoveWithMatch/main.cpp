//
//  main.cpp
//  RemoveWithMatch
//
//  Created by 조윤영 on 14/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/12973
//string.erase(i, n): i번째로부터 n개의 char을 삭제.

//순차적으로 짝짓는다고 생각하면 stack을 우선 고려해보기.

#include <iostream>
#include<string>
#include <stack>

using namespace std;


//
int solution(string s)
{
    stack<char> history;
    int answer = 0;
    
    for(int i=0; i<s.size(); i++) {
        if(!history.empty() && history.top() == s[i])history.pop();
        else history.push(s[i]);
    }
    
    if(history.empty())answer = 1;
    else answer = 0;
    
    return answer;
    
}


//시간초과
int solution2(string s)
{
    
    while(true) {
        if(s.size()==0)break;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i+1] == s[i]) {
                s.erase(i,2);
                break;
            }
            
            if(i == s.size()-1)return 0;
        }
    }
    
    
    return 1;
}
int main(int argc, const char * argv[]) {
    string s = "baabaa";
    cout<<solution(s);
    return 0;
}

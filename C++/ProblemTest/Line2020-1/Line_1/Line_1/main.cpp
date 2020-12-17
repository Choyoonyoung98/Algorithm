//
//  main.cpp
//  Line_1
//
//  Created by 조윤영 on 06/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

map<char,int> m;

map<char,char> match_m;
priority_queue<char> q;


void setMatch() {
    match_m[')'] = '(';
    match_m['}'] = '{';
    match_m[']'] = '[';
}

int solution(string inputString) {
    int answer = 0;
    
    setMatch();
    
    for(int i=0; i<inputString.size(); i++) {
        
        if(inputString[i] == '('||inputString[i] == ')' || inputString[i] == '{' || inputString[i] == '}' || inputString[i] == '[' ||inputString[i] == ']' ||inputString[i] == '<' ||inputString[i] == '>') {
            
            char currentChar = inputString[i];
            
            if(inputString[i] == ')' ||  inputString[i] == '}' || inputString[i] == ']' || inputString[i] == '>'){

                if(m[currentChar]>=m[match_m[currentChar]])continue;
            }

            m[currentChar]++;

            q.push(currentChar);
            
        }
    }

    
    while(!q.empty()){
        char current = q.top();
        q.pop();
        
        if(match_m[current] == q.top()){
            q.pop();
            
            answer++;
        }else{
            return -1;
        }
        
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

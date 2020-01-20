//
//  main.cpp
//  CorrectParenthesis
//
//  Created by 조윤영 on 20/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include<string>
#include <iostream>
#include <stack>

using namespace std;

string solution(string s)
{
    string answer;

    stack<char> temp;
    
    for(char c:s) {
        if(c == '(') {
            temp.push(c);
        }else { //)
            if(temp.empty())return "false";
            else {
                if(temp.top() =='(')temp.pop();
                else temp.push(c);
            }
        }
    }
    
    if(!temp.empty())answer = "false";
    else answer = "true";
    
    return answer;

}
int main(int arg, const char * argv[]) {
    cout<<solution("(()(");
    return 0;
}

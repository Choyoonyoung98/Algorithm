//
//  main.cpp
//  IronBar
//
//  Created by 조윤영 on 25/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
/*
 (문제)
 여러 개의 쇠막대기를 레이저로 절단하려고 합니다. 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자릅니다. 쇠막대기와 레이저의 배치는 다음 조건을 만족합니다.
 - 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있습니다.
 - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓습니다.
 - 각 쇠막대기를 자르는 레이저는 적어도 하나 존재합니다.
 - 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않습니다.
 */
/**************************************************/
//ReplaceAll 클래스: 문자열 안의 특정 문자를 교체해주는 클래스!
/**************************************************/
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string ReplaceAll(string &str, const string& from, const string& to) {
    size_t start_pos = 0;//string 처음부터 검사
    while((start_pos = str.find(from, start_pos)) != string::npos) //from을 찾을 수 없을 때까지
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); //중복 검사를 피하고 from.length() > to.length()인 경우를 위해서
    }
    return str;
}

//간단하게 생각해보자. 다른 사람의 풀이
int solution2(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    for(int i=0; i<arrangement.size(); i++) {//레이저인 경우
        if(arrangement[i] == '(' && i+1 < arrangement.size() && arrangement[i+1] == ')') {
            i++;
            answer+=s.size();
        }else if(arrangement[i] == '(' && i+1 < arrangement.size() && arrangement[i+1] !=')') {
            //쇠막대기 시작
            s.push(arrangement[i]);
        }else if(arrangement[i] == ')') {//쇠막대기 끝
            s.pop();
            answer++;
        }
        
    }
    
    return answer;
}
//윤영의 엉망진창 풀이 ㅋㅋㅋ
int solution(string arrangement) {
    string temp = arrangement;
    int answer = 0;
    int cnt = 0;
    
    stack<char>s;
    
    ReplaceAll(temp, "()","0");
    int acc = 0;
    for(auto c: temp) {
        if(c == ')') {
            acc=0;
            while(s.top() !='('){
                if(s.top() == '0') {
                    answer+=1;
                    acc+=1;
                }
                else {
                    acc+=(int)s.top();
                    answer+=(int)s.top();
                }
                s.pop();
            }

            answer+=1;
            s.pop(); //(
            s.push(acc);


        }else{ // ( 혹은 0을 만나면
             s.push(c);
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("()(((()())(())()))(())")<<endl;
    cout<<solution2("()(((()())(())()))(())");
    return 0;
}

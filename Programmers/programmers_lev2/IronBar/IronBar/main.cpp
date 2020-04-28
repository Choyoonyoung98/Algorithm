//
//  main.cpp
//  IronBar
//
//  Created by 조윤영 on 25/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//https://programmers.co.kr/learn/courses/30/lessons/42585
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

//20200427 풀이 - stack
int solution4(string arrangement) {
    int answer = 0;
    stack<char> bar;
    
    bool possibleOfLaser = true;
    
    for(int i=0; i<arrangement.size(); i++) {
        if(i == arrangement.size()-1){
            answer+=bar.size();
            break;
        }
        
        if(arrangement[i] == '(') {
            possibleOfLaser = true;
            bar.push('(');
        }else if(arrangement[i] == ')') {
            bar.pop();
            if(possibleOfLaser == true && bar.size() != 0) {
                //레이저임
                answer += bar.size();
            }else if(possibleOfLaser != true){
                answer +=1;
            }
            
            possibleOfLaser = false;
        }
    }
    
    return answer;
}


//보다 멋진 풀이
int solution3(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    for(int i=0; i< arrangement.length(); i++) {
        if(arrangement[i] == '(') s.push(arrangement[i]);
        else{
            s.pop();
            if(arrangement[i-1] == '(') answer +=s.size();
            else answer++;
            
        }
    }
    
    return answer;
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
    //3+3+1+3+1+2+1+1+1+1
    return 0;
}

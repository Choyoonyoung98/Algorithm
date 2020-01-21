//
//  main.cpp
//  TransferParenthesis
//
//  Created by 조윤영 on 20/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p);

string answer;

//'('의 개수와 ')'의 개수가 같음: 균형잡힌 괄호 문자열
//+ '('와 ')'의 짝이 맞을 경우 : 올바른 괄호 문자열
void makeCtoCorrect(string C, string V) {
    string correctC ="";
    if(C.size()>2){
        //앞 뒤 문자 제외한 나머지 문자 뒤집어서 correctC에 추가
        for(int i=1; i<C.size()-1; i++) {
            if(C[i] =='(') correctC+=')';
            else correctC+='(';
        }
    }
    
    
    answer +='(';
    
    if(V !="")solution(V);
    
    answer+=')';
    answer+=correctC;
    
    
}
void checkIfCisCorrect(string C, string V) {
    stack<char> temp;
    
    for(char c: C) {
        if(c == '(')temp.push(c);
        else {//)
            if(!temp.empty() && temp.top() == '(')temp.pop();
            else temp.push(c);
        }
    }
    
    if(!temp.empty()) makeCtoCorrect(C, V);//문자열 u가 "올바른 괄호 문자열"이 아니라면
    else {//문자열 u가 "올바른 괄호 문자열" 이라면
        answer+=C;
        
        if(V !="")solution(V);
    }
}
void seperateCandV(string sentence) {
    
    int leftCnt = 0;
    int rightCnt = 0;

    string C;
    string V;
    bool findC = false;
    
    for(char c: sentence) {
        if(findC == false) {
            C += c;
            if(c == '(')leftCnt++;
            else rightCnt++;
            if(leftCnt !=0 && rightCnt!=0 && leftCnt == rightCnt){
                findC = true;
            }
        }else{
            V += c;
        }
    }
    
    checkIfCisCorrect(C, V);
}

string solution(string p) {

    
    if(p == "")return "";
    
    seperateCandV(p);
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("()))((()");
    return 0;
}

//
//  main.cpp
//  MakeWeirdWord
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
    int cnt =1;
    for(int i=0; i<s.length(); i++) {
        //공백일 경우
        if(answer[i] == 32){
            cnt=1;
            continue;
        }
        answer[i] = (cnt%2 == 0)?tolower(answer[i]):toupper(answer[i]);
        cnt++;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("try hello world");
    return 0;
}

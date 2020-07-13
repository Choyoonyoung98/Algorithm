//
//  main.cpp
//  StringCompression
//
//  Created by 조윤영 on 08/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/60057
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX_SIZE 1001

using namespace std;

//*
int solution(string s) {
    int answerSize = MAX_SIZE;
    
    if(s.length() == 1)return 1;
    
    for(int i=1; i<=s.length()/2; i++) {//문자열 자를 단위
        int cnt = 1;
        string piece = s.substr(0,i);//0번째부터 i만큼 자른다.
        string nextPiece, answer;
        
        for(int j=i; j<s.length(); j+=i) {//처음부터 비교한다 단위크기만큼 점프하면서
            nextPiece = s.substr(j,i);//j에서 i 만큼 자른다.
            
            if(piece.compare(nextPiece) == 0) cnt++; //비교 문자가 같으면 count 증가
            else {//비교 문자가 같지 않으면? aa ab
                if(cnt == 1) { //첫 번째 문자라면
                    answer += piece;
                    piece = nextPiece;
                }else {//반복이 끝났음을 뜻함.
                    answer += to_string(cnt) + piece;
                    piece = nextPiece;
                    cnt = 1;
                }
            }
            
            if(j+i >= s.length()) {//*
                //aabbccd와 같은 상황에서 substr 기준을 넘어설때!
                //현재 남은 문자가 잘라야 하는 문자의 길이보다 작을때
                
                if(cnt != 1) {
                    answer += to_string(cnt) + piece;
                    break;
                }else {
                    answer += s.substr(j); //j부터 끝까지 덧붙인다.
                    break;
                }
            }
        }
        
        int newAnswerLength = answer.size();
        answerSize = min(answerSize, newAnswerLength);
    }
    
    return answerSize;
}

int main(int argc, const char * argv[]) {
    string s = "aabbaccc";
    solution(s);
    
    return 0;
}
//a a b b a c c c
//ab ab cd cd ab ab cd cd //ababcdcd ababcdcd
//ab ca bc de de //abc abc ded e
//abc abc abc abc ded ede ded ede
//abca bcab cabc dede dede dede //abcabc abcabc dedede dedede


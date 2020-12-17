//
//  main.cpp
//  LongestPalindrom
//
//  Created by 조윤영 on 02/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//문제 이름: 가장 긴 팰린드롬
//https://programmers.co.kr/learn/courses/30/lessons/12904
//Manacher's Algorithm O(N)

/*생각해보아야 할 문제.
 -팰린드롬이란,
 어떤 문자 기준으로 반복되는 문자열도 팰린드롬이지만, ->> ccacc
 기준없이 반복되는 문자열도 팰린드롬인 것을 잊지말아야 한다. ->> bccb
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maxLength = 1;

void check(string s, int standard) {
    int equal = 0;

    for(int i=0; i<standard; i++) {
        
        if(s[standard-(i+1)] != '#') {
            if(s[standard-(i+1)] == s[standard+(i+1)]){
                equal++;
            }
            else break;
        }
    }

    
    if(s[standard] == '#')maxLength = max(maxLength, equal*2);
    else maxLength = max(maxLength, equal*2+1);
    

}

int solution(string s)
{
    int answer=0;
    
    string transS = "#";
    
    for(char c: s) {
        transS +=c;
        transS +='#';
    }
    
    
    if(s.length() == 0)return 0;
    else if(s.length() == 1)return 1;
    
    for(int i=2; i<transS.size()-2; i++) {
        int standard = i;
        check(transS, standard);
    }
    
    answer = maxLength;
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("baaba");
    return 0;
}

//
//  main.cpp
//  FindPandY
//
//  Created by 조윤영 on 11/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 문제 설명
 대문자와 소문자가 섞여있는 문자열 s가 주어집니다. s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.
 
 예를 들어 s가 pPoooyY면 true를 return하고 Pyy라면 false를 return합니다.
 */

#include <iostream>
#include <algorithm>
#include <string>



using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int countP = 0;
    int countY = 0;
    
    std::transform(s.begin(), s.end(),s.begin(), ::tolower);//모두 소문자로 만든다.
    
    for(int i=0; i<s.length();i++) {
        if(s.at(i) == 'p')countP++;
        if(s.at(i) == 'y')countY++;
    }
    
    answer = (countP== countY || (countP==0&&countY==0))?true:false;
    

    return answer;
}
int main(int argc, const char * argv[]) {
    string s = "pPooyY";
    cout<<solution(s);
    return 0;
}

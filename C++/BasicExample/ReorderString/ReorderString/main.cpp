//
//  main.cpp
//  ReorderString
//
//  Created by 조윤영 on 2020/08/11.
//  Copyright © 2020 조윤영. All rights reserved.
//
//문자열 재정렬

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

string solution(string target) {
    string answer;
    sort(target.begin(), target.end());
    string isString;
    int isInteger = 0;
    cout<<target<<endl;
    for(int i=0; i<target.size(); i++ ) {
        if(isdigit(target[i]))  {
            isInteger += target[i]  - '0';
        } else {
            isString = target.substr(i);
            break;
        }
    }
    
    answer = isString + to_string(isInteger);
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("AJKDLSI412K4JSJ9D")<<"\n";
    //1.K1KA5CB7
    return 0;
}

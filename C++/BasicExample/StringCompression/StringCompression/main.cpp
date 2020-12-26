//
//  main.cpp
//  StringCompression
//
//  Created by 조윤영 on 2020/08/11.
//  Copyright © 2020 조윤영. All rights reserved.
//
//문자열 압축

#include <iostream>
#include <string>
#include <algorithm>
#define MAX_SIZE 1001

using namespace std;

int solution(string s) {
    int answer = MAX_SIZE;
    
    if(s.size() == 1) return 1;
    for(int i=1; i<s.size()/2+1; i++) {
        
        string temp = "";
        string targetString = s.substr(0, i);
        int sameCnt = 1;
        
        for(int j=i; j<s.size(); j++) {
//            cout<<temp<<":"<<targetString<<"VS"<<s.substr(j, i)<<endl;
            if(s.substr(j, i) == targetString) {
                sameCnt++;
                j += (i-1);
            } else {
                if(sameCnt != 1) {
                    temp += to_string(sameCnt);
                }
                temp += targetString;
                sameCnt = 1;
                targetString = s.substr(j, i);
                j += (i-1);
            }
        }
        //끝에 처리되지 못한 문자열 처리
        if(sameCnt != 1) {
            temp += to_string(sameCnt);
        }
        temp += targetString;
//        cout<<temp<<endl;
//        cout<<"--------------------"<<endl;
        int tempSize = temp.size();
        answer = min(answer, tempSize);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s =  "xababcdcdababcdcd";
    cout<<solution(s);
    return 0;
}

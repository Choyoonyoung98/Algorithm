//
//  main.cpp
//  WordCompression60057
//
//  Created by 조윤영 on 2021/01/09.
//
#define INF 1e9
#include <cmath>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = INF;
    string result = "";
    if(s.size() == 1) return 1;
    
    for(int cutSize=1; cutSize<=s.size()/2; cutSize++) { //단위
        string prevWord = "";
        result = "";
        int cnt = 1;
        for(int i=0; i<s.size(); i++) {

            if((s.substr(i, cutSize) != prevWord)) {
                if(cnt > 1) {
                    result += to_string(cnt);
                    result += prevWord;
                    cnt = 1;
                } else if( i != 0) result += prevWord;
                
                prevWord = s.substr(i, cutSize);
            } else {
                cnt++;
            }
            
            i += (cutSize - 1);

            if(i+1 >= s.size()) {
                if(cnt > 1) {
                    result += to_string(cnt);
                    result += prevWord;
                } else result += prevWord;
            }
        }
        int resultSize = result.size();
        answer = min(answer, resultSize);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {

    cout<<solution("xababcdcdababcdcd");
    return 0;
}

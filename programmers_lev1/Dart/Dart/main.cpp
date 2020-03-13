//
//  main.cpp
//  Dart
//
//  Created by 조윤영 on 13/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int solution(string dartResult) {
    int answer = 0;
    
    string currentScore = "";
    int pastScore = 0;
    int powScore = 0;
    char powScores[3] = {'S','D','T'};
    
    char cResult;
    int iScore = 0;
    
    for(int i=0; i<dartResult.size(); i++) {
        cResult = dartResult[i];
        
        if(isdigit(cResult)!= 0) {
            currentScore += cResult;
        }else{
            if(isdigit(dartResult[i-1])!=0 )iScore = stoi(currentScore);
            
            if(cResult == 'S' || cResult == 'D' || cResult == 'T') {
                for(int j=0; j<3; j++) {
                    if(cResult == powScores[j])powScore = j+1;
                    
                }
            
                iScore = pow(iScore, powScore);
            }
            else if(cResult == '*') { //2배
                iScore *= 2; //현재 점수 곱하기 2
                
                answer += pastScore;
            }
            else if(cResult == '#') { //-1
                iScore *= -1;
            }
            
            if(i == dartResult.size()-1 || isdigit(dartResult[i+1]) != 0) {
                
                answer += iScore;
                pastScore = iScore;//과거의 점수로 만든다.
                currentScore = "";

            }
            
        }
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    string dartResult = "1D2S3T*";
    solution(dartResult);
    
    return 0;
}
